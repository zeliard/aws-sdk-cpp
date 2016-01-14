// AwsCppSdkWinSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <aws/core/client/AsyncCallerContext.h>
#include <aws/core/client/ClientConfiguration.h>
#include <aws/core/client/CoreErrors.h>
#include <aws/core/auth/AWSCredentialsProviderChain.h>
#include <aws/core/http/HttpTypes.h>
#include <aws/dynamodb/DynamoDBClient.h>
#include <aws/dynamodb/DynamoDBErrors.h>
#include <aws/core/utils/UnreferencedParam.h>
#include <aws/core/utils/Outcome.h>
#include <aws/core/utils/memory/stl/AWSSet.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>
#include <aws/core/utils/ratelimiter/DefaultRateLimiter.h>
#include <aws/dynamodb/model/CreateTableRequest.h>
#include <aws/dynamodb/model/DeleteTableRequest.h>
#include <aws/dynamodb/model/DescribeTableRequest.h>
#include <aws/dynamodb/model/ListTablesRequest.h>
#include <aws/dynamodb/model/UpdateTableRequest.h>
#include <aws/dynamodb/model/PutItemRequest.h>
#include <aws/dynamodb/model/GetItemRequest.h>
#include <aws/dynamodb/model/ScanRequest.h>
#include <aws/dynamodb/model/UpdateItemRequest.h>
#include <aws/dynamodb/model/DeleteItemRequest.h>

#include "LockFreeMemorySystem.h"
#include "LockFreeExecutor.h"

using namespace Aws;
using namespace Aws::Auth;
using namespace Aws::Http;
using namespace Aws::Client;
using namespace Aws::DynamoDB;
using namespace Aws::DynamoDB::Model;

static const char* HASH_KEY_NAME = "HashKey";
static const char* SIMPLE_TABLE = "TestSimpleTable";
static const char* ALLOCATION_TAG = "DynamoDbTest";



class DynamoDbTest
{
public:
	void SetUpTest()
	{
		auto limiter = Aws::MakeShared<Aws::Utils::RateLimits::DefaultRateLimiter<>>(ALLOCATION_TAG, 200000);
		auto executor = Aws::MakeShared<LockFreeExecutor>(ALLOCATION_TAG);

		ClientConfiguration config;
		config.scheme = Scheme::HTTPS;
		config.connectTimeoutMs = 30000;
		config.requestTimeoutMs = 30000;
		config.readRateLimiter = limiter;
		config.writeRateLimiter = limiter;
		config.httpLibOverride = Aws::Http::TransferLibType::WIN_HTTP_CLIENT;
		config.region = Region::AP_NORTHEAST_2;
		config.executor = executor;

		m_client = Aws::MakeShared<DynamoDBClient>(ALLOCATION_TAG, config);
	}
	
	void CreateTableTest()
	{
		CreateTableRequest createTableRequest;
		AttributeDefinition hashKey;
		hashKey.SetAttributeName(HASH_KEY_NAME);
		hashKey.SetAttributeType(ScalarAttributeType::S);
		createTableRequest.AddAttributeDefinitions(hashKey);
		KeySchemaElement hashKeySchemaElement;
		hashKeySchemaElement.WithAttributeName(HASH_KEY_NAME).WithKeyType(KeyType::HASH);
		createTableRequest.AddKeySchema(hashKeySchemaElement);
		ProvisionedThroughput provisionedThroughput;
		provisionedThroughput.SetReadCapacityUnits(10);
		provisionedThroughput.SetWriteCapacityUnits(10);
		createTableRequest.WithProvisionedThroughput(provisionedThroughput);
		createTableRequest.WithTableName(SIMPLE_TABLE);

		CreateTableOutcome createTableOutcome = m_client->CreateTable(createTableRequest);
		if (createTableOutcome.IsSuccess())
		{
			printf("[OK] CreateTable: %s\n", createTableOutcome.GetResult().GetTableDescription().GetTableName().c_str());
		}
		else
		{
			assert(createTableOutcome.GetError().GetErrorType() == DynamoDBErrors::RESOURCE_IN_USE);
		}

		/// Need to wait for the table to finish creating the table

		DescribeTableRequest describeTableRequest;
		describeTableRequest.SetTableName(SIMPLE_TABLE);

		DescribeTableOutcome outcome = m_client->DescribeTable(describeTableRequest);

		while (true)
		{
			assert(outcome.IsSuccess());
			if (outcome.GetResult().GetTable().GetTableStatus() == TableStatus::ACTIVE)
			{
				break;
			}
			else
			{
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}

			outcome = m_client->DescribeTable(describeTableRequest);
		}
	}

	void DeleteTableTest()
	{
		DeleteTableRequest deleteTableRequest;
		deleteTableRequest.SetTableName(SIMPLE_TABLE);

		DeleteTableOutcome deleteTableOutcome = m_client->DeleteTable(deleteTableRequest);

		if (!deleteTableOutcome.IsSuccess())
		{
			// It's okay if the table has already beed deleted
			assert(DynamoDBErrors::RESOURCE_NOT_FOUND == deleteTableOutcome.GetError().GetErrorType());
		}
		else
		{
			printf("[OK] DeleteTable: %s\n", deleteTableOutcome.GetResult().GetTableDescription().GetTableName().c_str());
		}
	}

	void PutAndGetItemAsyncTest()
	{
		auto putItemHandler = std::bind(&DynamoDbTest::PutItemOutcomeReceived, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
		auto getItemHandler = std::bind(&DynamoDbTest::GetItemOutcomeReceived, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);

		/// now put 50 items in the table asynchronously
		Aws::String testValueColumnName = "TestValue";
		Aws::StringStream ss;

		for (unsigned i = 0; i < 50; ++i)
		{
			ss << HASH_KEY_NAME << i;
			PutItemRequest putItemRequest;
			putItemRequest.SetTableName(SIMPLE_TABLE);
			AttributeValue hashKeyAttribute;
			hashKeyAttribute.SetS(ss.str());
			ss.str("");
			putItemRequest.AddItem(HASH_KEY_NAME, hashKeyAttribute);
			AttributeValue testValueAttribute;
			ss << testValueColumnName << i;
			testValueAttribute.SetS(ss.str());
			putItemRequest.AddItem(testValueColumnName, testValueAttribute);
			ss.str("");
			m_client->PutItemAsync(putItemRequest, putItemHandler);
		}

		/// wait for the callbacks to finish.
		std::unique_lock<std::mutex> putItemResultLock(putItemResultMutex);
		putItemResultSemaphore.wait(putItemResultLock);

		/// now we get the items we were supposed to be putting and make sure they were put successfully.
		for (unsigned i = 0; i < 50; ++i)
		{
			GetItemRequest getItemRequest;
			ss << HASH_KEY_NAME << i;
			AttributeValue hashKey;
			hashKey.SetS(ss.str());
			getItemRequest.AddKey(HASH_KEY_NAME, hashKey);
			getItemRequest.SetTableName(SIMPLE_TABLE);

			Aws::Vector<Aws::String> attributesToGet;
			attributesToGet.push_back(HASH_KEY_NAME);
			attributesToGet.push_back(testValueColumnName);
			ss.str("");
			m_client->GetItemAsync(getItemRequest, getItemHandler);
		}

		/// wait for the callbacks to finish.
		std::unique_lock<std::mutex> getItemResultLock(getItemResultMutex);
		getItemResultSemaphore.wait(getItemResultLock);

		for (unsigned i = 0; i < 50; ++i)
		{
			GetItemOutcome outcome = getItemResultsFromCallbackTest[i];
			assert(outcome.IsSuccess());

			GetItemResult result = outcome.GetResult();
			Aws::Map<Aws::String, AttributeValue> returnedItemCollection = result.GetItem();

			printf("%s\n", returnedItemCollection[testValueColumnName].GetS().c_str());
		}

	}


public:
	void PutItemOutcomeReceived(const DynamoDBClient* sender, const PutItemRequest& request, const PutItemOutcome& outcome, const std::shared_ptr<const AsyncCallerContext>& context)
	{
		AWS_UNREFERENCED_PARAM(sender);
		AWS_UNREFERENCED_PARAM(request);
		AWS_UNREFERENCED_PARAM(context);

		std::lock_guard<std::mutex> locker(putItemResultMutex);
		putItemResultsFromCallbackTest.push_back(outcome);

		if (putItemResultsFromCallbackTest.size() == 50)
		{
			putItemResultSemaphore.notify_all();
		}
	}

	void GetItemOutcomeReceived(const DynamoDBClient* sender, const GetItemRequest& request, const GetItemOutcome& outcome, const std::shared_ptr<const AsyncCallerContext>& context)
	{
		AWS_UNREFERENCED_PARAM(sender);
		AWS_UNREFERENCED_PARAM(request);
		AWS_UNREFERENCED_PARAM(context);

		std::lock_guard<std::mutex> locker(getItemResultMutex);
		getItemResultsFromCallbackTest.push_back(outcome);

		if (getItemResultsFromCallbackTest.size() == 50)
		{
			getItemResultSemaphore.notify_all();
		}
	}


private:

	std::shared_ptr<DynamoDBClient> m_client;

	std::mutex putItemResultMutex;
	std::condition_variable putItemResultSemaphore;

	std::mutex getItemResultMutex;
	std::condition_variable getItemResultSemaphore;

	Aws::Vector<PutItemOutcome> putItemResultsFromCallbackTest;
	Aws::Vector<GetItemOutcome> getItemResultsFromCallbackTest;
};


int _tmain(int argc, _TCHAR* argv[])
{
	LockFreeMemorySystem memorySystem;
	Aws::Utils::Memory::InitializeAWSMemorySystem(memorySystem);

	/// DynamoDB Test Sample
	{
		DynamoDbTest test;
		test.SetUpTest();
		
		/// Create a table and verify it's output
		test.CreateTableTest();

		/// Put/Get items and then wait
		test.PutAndGetItemAsyncTest();

		/// Delete a table
		test.DeleteTableTest();
	}

	Aws::Utils::Memory::ShutdownAWSMemorySystem();
	
	printf("done!\n");
	return 0;
}


