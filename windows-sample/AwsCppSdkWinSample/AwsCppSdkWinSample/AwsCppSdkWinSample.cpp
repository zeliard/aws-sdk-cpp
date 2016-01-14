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
	std::shared_ptr<DynamoDBClient> m_client;
	
	void PutItemTest()
	{
		auto putItemHandler = std::bind(&DynamoDbTest::PutItemOutcomeReceived, this, std::placeholders::_1, std::placeholders::_2,
			std::placeholders::_3, std::placeholders::_4);

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
	}

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

private:

	

	std::mutex putItemResultMutex;
	std::condition_variable putItemResultSemaphore;

	Aws::Vector<PutItemOutcome> putItemResultsFromCallbackTest;
};


int _tmain(int argc, _TCHAR* argv[])
{
	LockFreeMemorySystem memorySystem;
	Aws::Utils::Memory::InitializeAWSMemorySystem(memorySystem);

	/// DynamoDB Test Sample
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
		auto dynamoDbClient = Aws::MakeShared<DynamoDBClient>(ALLOCATION_TAG, config);

		

		/// Create a table and verify it's output
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

			CreateTableOutcome createTableOutcome = dynamoDbClient->CreateTable(createTableRequest);
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
			
			DescribeTableOutcome outcome = dynamoDbClient->DescribeTable(describeTableRequest);

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

				outcome = dynamoDbClient->DescribeTable(describeTableRequest);
			}

		}

		/// Put items
		{
			DynamoDbTest putTest;
			putTest.m_client = dynamoDbClient;

			putTest.PutItemTest();


		}

		/// Delete a table
		{
			DeleteTableRequest deleteTableRequest;
			deleteTableRequest.SetTableName(SIMPLE_TABLE);

			DeleteTableOutcome deleteTableOutcome = dynamoDbClient->DeleteTable(deleteTableRequest);

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
	} ///< end of test

	Aws::Utils::Memory::ShutdownAWSMemorySystem();
	
	printf("done!\n");
	return 0;
}


