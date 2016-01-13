/*
* Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#pragma once
#include <aws/dynamodb/DynamoDB_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace DynamoDB
{
namespace Model
{
  /*
    <p>Represents the provisioned throughput settings for the table, consisting of read and write capacity units, along with data about increases and decreases.</p>
  */
  class AWS_DYNAMODB_API ProvisionedThroughputDescription
  {
  public:
    ProvisionedThroughputDescription();
    ProvisionedThroughputDescription(const Aws::Utils::Json::JsonValue& jsonValue);
    ProvisionedThroughputDescription& operator=(const Aws::Utils::Json::JsonValue& jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;

    /*
     <p>The date and time of the last provisioned throughput increase for this table.</p>
    */
    inline const Aws::String& GetLastIncreaseDateTime() const{ return m_lastIncreaseDateTime; }

    /*
     <p>The date and time of the last provisioned throughput increase for this table.</p>
    */
    inline void SetLastIncreaseDateTime(const Aws::String& value) { m_lastIncreaseDateTimeHasBeenSet = true; m_lastIncreaseDateTime = value; }

    /*
     <p>The date and time of the last provisioned throughput increase for this table.</p>
    */
    inline void SetLastIncreaseDateTime(Aws::String&& value) { m_lastIncreaseDateTimeHasBeenSet = true; m_lastIncreaseDateTime = value; }

    /*
     <p>The date and time of the last provisioned throughput increase for this table.</p>
    */
    inline void SetLastIncreaseDateTime(const char* value) { m_lastIncreaseDateTimeHasBeenSet = true; m_lastIncreaseDateTime.assign(value); }

    /*
     <p>The date and time of the last provisioned throughput increase for this table.</p>
    */
    inline ProvisionedThroughputDescription& WithLastIncreaseDateTime(const Aws::String& value) { SetLastIncreaseDateTime(value); return *this;}

    /*
     <p>The date and time of the last provisioned throughput increase for this table.</p>
    */
    inline ProvisionedThroughputDescription& WithLastIncreaseDateTime(Aws::String&& value) { SetLastIncreaseDateTime(value); return *this;}

    /*
     <p>The date and time of the last provisioned throughput increase for this table.</p>
    */
    inline ProvisionedThroughputDescription& WithLastIncreaseDateTime(const char* value) { SetLastIncreaseDateTime(value); return *this;}

    /*
     <p>The date and time of the last provisioned throughput decrease for this table.</p>
    */
    inline const Aws::String& GetLastDecreaseDateTime() const{ return m_lastDecreaseDateTime; }

    /*
     <p>The date and time of the last provisioned throughput decrease for this table.</p>
    */
    inline void SetLastDecreaseDateTime(const Aws::String& value) { m_lastDecreaseDateTimeHasBeenSet = true; m_lastDecreaseDateTime = value; }

    /*
     <p>The date and time of the last provisioned throughput decrease for this table.</p>
    */
    inline void SetLastDecreaseDateTime(Aws::String&& value) { m_lastDecreaseDateTimeHasBeenSet = true; m_lastDecreaseDateTime = value; }

    /*
     <p>The date and time of the last provisioned throughput decrease for this table.</p>
    */
    inline void SetLastDecreaseDateTime(const char* value) { m_lastDecreaseDateTimeHasBeenSet = true; m_lastDecreaseDateTime.assign(value); }

    /*
     <p>The date and time of the last provisioned throughput decrease for this table.</p>
    */
    inline ProvisionedThroughputDescription& WithLastDecreaseDateTime(const Aws::String& value) { SetLastDecreaseDateTime(value); return *this;}

    /*
     <p>The date and time of the last provisioned throughput decrease for this table.</p>
    */
    inline ProvisionedThroughputDescription& WithLastDecreaseDateTime(Aws::String&& value) { SetLastDecreaseDateTime(value); return *this;}

    /*
     <p>The date and time of the last provisioned throughput decrease for this table.</p>
    */
    inline ProvisionedThroughputDescription& WithLastDecreaseDateTime(const char* value) { SetLastDecreaseDateTime(value); return *this;}

    /*
     <p>The number of provisioned throughput decreases for this table during this UTC calendar day. For current maximums on provisioned throughput decreases, see <a href="http://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Limits.html">Limits</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    */
    inline long long GetNumberOfDecreasesToday() const{ return m_numberOfDecreasesToday; }

    /*
     <p>The number of provisioned throughput decreases for this table during this UTC calendar day. For current maximums on provisioned throughput decreases, see <a href="http://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Limits.html">Limits</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    */
    inline void SetNumberOfDecreasesToday(long long value) { m_numberOfDecreasesTodayHasBeenSet = true; m_numberOfDecreasesToday = value; }

    /*
     <p>The number of provisioned throughput decreases for this table during this UTC calendar day. For current maximums on provisioned throughput decreases, see <a href="http://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Limits.html">Limits</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    */
    inline ProvisionedThroughputDescription& WithNumberOfDecreasesToday(long long value) { SetNumberOfDecreasesToday(value); return *this;}

    /*
     <p>The maximum number of strongly consistent reads consumed per second before DynamoDB returns a <i>ThrottlingException</i>. Eventually consistent reads require less effort than strongly consistent reads, so a setting of 50 <i>ReadCapacityUnits</i> per second provides 100 eventually consistent <i>ReadCapacityUnits</i> per second.</p>
    */
    inline long long GetReadCapacityUnits() const{ return m_readCapacityUnits; }

    /*
     <p>The maximum number of strongly consistent reads consumed per second before DynamoDB returns a <i>ThrottlingException</i>. Eventually consistent reads require less effort than strongly consistent reads, so a setting of 50 <i>ReadCapacityUnits</i> per second provides 100 eventually consistent <i>ReadCapacityUnits</i> per second.</p>
    */
    inline void SetReadCapacityUnits(long long value) { m_readCapacityUnitsHasBeenSet = true; m_readCapacityUnits = value; }

    /*
     <p>The maximum number of strongly consistent reads consumed per second before DynamoDB returns a <i>ThrottlingException</i>. Eventually consistent reads require less effort than strongly consistent reads, so a setting of 50 <i>ReadCapacityUnits</i> per second provides 100 eventually consistent <i>ReadCapacityUnits</i> per second.</p>
    */
    inline ProvisionedThroughputDescription& WithReadCapacityUnits(long long value) { SetReadCapacityUnits(value); return *this;}

    /*
     <p>The maximum number of writes consumed per second before DynamoDB returns a <i>ThrottlingException</i>.</p>
    */
    inline long long GetWriteCapacityUnits() const{ return m_writeCapacityUnits; }

    /*
     <p>The maximum number of writes consumed per second before DynamoDB returns a <i>ThrottlingException</i>.</p>
    */
    inline void SetWriteCapacityUnits(long long value) { m_writeCapacityUnitsHasBeenSet = true; m_writeCapacityUnits = value; }

    /*
     <p>The maximum number of writes consumed per second before DynamoDB returns a <i>ThrottlingException</i>.</p>
    */
    inline ProvisionedThroughputDescription& WithWriteCapacityUnits(long long value) { SetWriteCapacityUnits(value); return *this;}

  private:
    Aws::String m_lastIncreaseDateTime;
    bool m_lastIncreaseDateTimeHasBeenSet;
    Aws::String m_lastDecreaseDateTime;
    bool m_lastDecreaseDateTimeHasBeenSet;
    long long m_numberOfDecreasesToday;
    bool m_numberOfDecreasesTodayHasBeenSet;
    long long m_readCapacityUnits;
    bool m_readCapacityUnitsHasBeenSet;
    long long m_writeCapacityUnits;
    bool m_writeCapacityUnitsHasBeenSet;
  };

} // namespace Model
} // namespace DynamoDB
} // namespace Aws
