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
#include <aws/email/SES_EXPORTS.h>
#include <aws/email/SESRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace SES
{
namespace Model
{

  /*
  */
  class AWS_SES_API ListReceiptRuleSetsRequest : public SESRequest
  {
  public:
    ListReceiptRuleSetsRequest();
    Aws::String SerializePayload() const override;


    
    inline const Aws::String& GetPageToken() const{ return m_pageToken; }

    
    inline void SetPageToken(const Aws::String& value) { m_pageTokenHasBeenSet = true; m_pageToken = value; }

    
    inline void SetPageToken(Aws::String&& value) { m_pageTokenHasBeenSet = true; m_pageToken = value; }

    
    inline void SetPageToken(const char* value) { m_pageTokenHasBeenSet = true; m_pageToken.assign(value); }

    
    inline ListReceiptRuleSetsRequest& WithPageToken(const Aws::String& value) { SetPageToken(value); return *this;}

    
    inline ListReceiptRuleSetsRequest& WithPageToken(Aws::String&& value) { SetPageToken(value); return *this;}

    
    inline ListReceiptRuleSetsRequest& WithPageToken(const char* value) { SetPageToken(value); return *this;}

    
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    
    inline void SetNextToken(const Aws::String& value) { m_nextTokenHasBeenSet = true; m_nextToken = value; }

    
    inline void SetNextToken(Aws::String&& value) { m_nextTokenHasBeenSet = true; m_nextToken = value; }

    
    inline void SetNextToken(const char* value) { m_nextTokenHasBeenSet = true; m_nextToken.assign(value); }

    
    inline ListReceiptRuleSetsRequest& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    
    inline ListReceiptRuleSetsRequest& WithNextToken(Aws::String&& value) { SetNextToken(value); return *this;}

    
    inline ListReceiptRuleSetsRequest& WithNextToken(const char* value) { SetNextToken(value); return *this;}

  private:
    Aws::String m_pageToken;
    bool m_pageTokenHasBeenSet;
    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet;
  };

} // namespace Model
} // namespace SES
} // namespace Aws
