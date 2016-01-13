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


#include <assert.h>

using namespace Aws;
using namespace Aws::Auth;
using namespace Aws::Http;
using namespace Aws::Client;
using namespace Aws::DynamoDB;
using namespace Aws::DynamoDB::Model;

static const char* HASH_KEY_NAME = "HashKey";
static const char* SIMPLE_TABLE = "TestSimpleTable";
static const char* ALLOCATION_TAG = "DynamoDbTest";


std::shared_ptr<DynamoDBClient> g_client(nullptr);


DescribeTableResult WaitUntilActive(const Aws::String tableName);

int _tmain(int argc, _TCHAR* argv[])
{
	auto limiter = Aws::MakeShared<Aws::Utils::RateLimits::DefaultRateLimiter<>>(ALLOCATION_TAG, 200000);

	ClientConfiguration config;
	config.scheme = Scheme::HTTPS;
	config.connectTimeoutMs = 30000;
	config.requestTimeoutMs = 30000;
	config.readRateLimiter = limiter;
	config.writeRateLimiter = limiter;
	config.httpLibOverride = Aws::Http::TransferLibType::WIN_HTTP_CLIENT;
	config.region = Region::AP_NORTHEAST_2;

	g_client = Aws::MakeShared<DynamoDBClient>(ALLOCATION_TAG, config);

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

		CreateTableOutcome createTableOutcome = g_client->CreateTable(createTableRequest);
		if (createTableOutcome.IsSuccess())
		{
			printf("CreateTable: %s\n", createTableOutcome.GetResult().GetTableDescription().GetTableName().c_str());
		}
		else
		{
			assert(createTableOutcome.GetError().GetErrorType() == DynamoDBErrors::RESOURCE_IN_USE);
		}
		//since we need to wait for the table to finish creating anyways,
		//let's go ahead and test describe table api while we are at it.
		WaitUntilActive(SIMPLE_TABLE);
	}

	/// Put items
	{
		AttributeValue homer;
		homer.SetS("Homer");

		AttributeValue bart;
		bart.SetS("Bart");

		AttributeValue hashKeyAttribute;

		PutItemRequest putRequest;
		putRequest.SetTableName(SIMPLE_TABLE);
		hashKeyAttribute.SetS("TestItem1");
		putRequest.AddItem(HASH_KEY_NAME, hashKeyAttribute);
		putRequest.AddItem("Simpson", homer);
		PutItemOutcome result1 = g_client->PutItem(putRequest);

		assert(result1.IsSuccess());

		PutItemRequest putRequest2;
		putRequest2.SetTableName(SIMPLE_TABLE);
		hashKeyAttribute.SetS("TestItem2");
		putRequest2.AddItem(HASH_KEY_NAME, hashKeyAttribute);
		putRequest2.AddItem("Simpson", bart);
		PutItemOutcome result2 = g_client->PutItem(putRequest2);

		assert(result2.IsSuccess());
	}

	/// Delete a table
	{
		DeleteTableRequest deleteTableRequest;
		deleteTableRequest.SetTableName(SIMPLE_TABLE);

		DeleteTableOutcome deleteTableOutcome = g_client->DeleteTable(deleteTableRequest);

		if (!deleteTableOutcome.IsSuccess())
		{
			// It's okay if the table has already beed deleted
			assert(DynamoDBErrors::RESOURCE_NOT_FOUND == deleteTableOutcome.GetError().GetErrorType());
		}
	}

	return 0;
}


DescribeTableResult WaitUntilActive(const Aws::String tableName)
{
	DescribeTableRequest describeTableRequest;
	describeTableRequest.SetTableName(tableName);
	bool shouldContinue = true;
	DescribeTableOutcome outcome = g_client->DescribeTable(describeTableRequest);

	while (shouldContinue)
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

		outcome = g_client->DescribeTable(describeTableRequest);
	}

	return outcome.GetResult();
}
