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
#include <aws/logs/CloudWatchLogs_EXPORTS.h>
#include <aws/logs/CloudWatchLogsRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace CloudWatchLogs
{
namespace Model
{

  /*
  */
  class AWS_CLOUDWATCHLOGS_API DeleteLogStreamRequest : public CloudWatchLogsRequest
  {
  public:
    DeleteLogStreamRequest();
    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /*
     <p>The name of the log group under which the log stream to delete belongs.</p>
    */
    inline const Aws::String& GetLogGroupName() const{ return m_logGroupName; }

    /*
     <p>The name of the log group under which the log stream to delete belongs.</p>
    */
    inline void SetLogGroupName(const Aws::String& value) { m_logGroupNameHasBeenSet = true; m_logGroupName = value; }

    /*
     <p>The name of the log group under which the log stream to delete belongs.</p>
    */
    inline void SetLogGroupName(Aws::String&& value) { m_logGroupNameHasBeenSet = true; m_logGroupName = value; }

    /*
     <p>The name of the log group under which the log stream to delete belongs.</p>
    */
    inline void SetLogGroupName(const char* value) { m_logGroupNameHasBeenSet = true; m_logGroupName.assign(value); }

    /*
     <p>The name of the log group under which the log stream to delete belongs.</p>
    */
    inline DeleteLogStreamRequest& WithLogGroupName(const Aws::String& value) { SetLogGroupName(value); return *this;}

    /*
     <p>The name of the log group under which the log stream to delete belongs.</p>
    */
    inline DeleteLogStreamRequest& WithLogGroupName(Aws::String&& value) { SetLogGroupName(value); return *this;}

    /*
     <p>The name of the log group under which the log stream to delete belongs.</p>
    */
    inline DeleteLogStreamRequest& WithLogGroupName(const char* value) { SetLogGroupName(value); return *this;}

    /*
     <p>The name of the log stream to delete.</p>
    */
    inline const Aws::String& GetLogStreamName() const{ return m_logStreamName; }

    /*
     <p>The name of the log stream to delete.</p>
    */
    inline void SetLogStreamName(const Aws::String& value) { m_logStreamNameHasBeenSet = true; m_logStreamName = value; }

    /*
     <p>The name of the log stream to delete.</p>
    */
    inline void SetLogStreamName(Aws::String&& value) { m_logStreamNameHasBeenSet = true; m_logStreamName = value; }

    /*
     <p>The name of the log stream to delete.</p>
    */
    inline void SetLogStreamName(const char* value) { m_logStreamNameHasBeenSet = true; m_logStreamName.assign(value); }

    /*
     <p>The name of the log stream to delete.</p>
    */
    inline DeleteLogStreamRequest& WithLogStreamName(const Aws::String& value) { SetLogStreamName(value); return *this;}

    /*
     <p>The name of the log stream to delete.</p>
    */
    inline DeleteLogStreamRequest& WithLogStreamName(Aws::String&& value) { SetLogStreamName(value); return *this;}

    /*
     <p>The name of the log stream to delete.</p>
    */
    inline DeleteLogStreamRequest& WithLogStreamName(const char* value) { SetLogStreamName(value); return *this;}

  private:
    Aws::String m_logGroupName;
    bool m_logGroupNameHasBeenSet;
    Aws::String m_logStreamName;
    bool m_logStreamNameHasBeenSet;
  };

} // namespace Model
} // namespace CloudWatchLogs
} // namespace Aws
