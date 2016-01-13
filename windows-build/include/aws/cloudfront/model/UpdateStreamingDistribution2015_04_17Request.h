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
#include <aws/cloudfront/CloudFront_EXPORTS.h>
#include <aws/cloudfront/CloudFrontRequest.h>
#include <aws/cloudfront/model/StreamingDistributionConfig.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace CloudFront
{
namespace Model
{

  /*
    The request to update a streaming distribution.
  */
  class AWS_CLOUDFRONT_API UpdateStreamingDistribution2015_04_17Request : public CloudFrontRequest
  {
  public:
    UpdateStreamingDistribution2015_04_17Request();
    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /*
     The streaming distribution's configuration information.
    */
    inline const StreamingDistributionConfig& GetStreamingDistributionConfig() const{ return m_streamingDistributionConfig; }

    /*
     The streaming distribution's configuration information.
    */
    inline void SetStreamingDistributionConfig(const StreamingDistributionConfig& value) { m_streamingDistributionConfigHasBeenSet = true; m_streamingDistributionConfig = value; }

    /*
     The streaming distribution's configuration information.
    */
    inline void SetStreamingDistributionConfig(StreamingDistributionConfig&& value) { m_streamingDistributionConfigHasBeenSet = true; m_streamingDistributionConfig = value; }

    /*
     The streaming distribution's configuration information.
    */
    inline UpdateStreamingDistribution2015_04_17Request& WithStreamingDistributionConfig(const StreamingDistributionConfig& value) { SetStreamingDistributionConfig(value); return *this;}

    /*
     The streaming distribution's configuration information.
    */
    inline UpdateStreamingDistribution2015_04_17Request& WithStreamingDistributionConfig(StreamingDistributionConfig&& value) { SetStreamingDistributionConfig(value); return *this;}

    /*
     The streaming distribution's id.
    */
    inline const Aws::String& GetId() const{ return m_id; }

    /*
     The streaming distribution's id.
    */
    inline void SetId(const Aws::String& value) { m_idHasBeenSet = true; m_id = value; }

    /*
     The streaming distribution's id.
    */
    inline void SetId(Aws::String&& value) { m_idHasBeenSet = true; m_id = value; }

    /*
     The streaming distribution's id.
    */
    inline void SetId(const char* value) { m_idHasBeenSet = true; m_id.assign(value); }

    /*
     The streaming distribution's id.
    */
    inline UpdateStreamingDistribution2015_04_17Request& WithId(const Aws::String& value) { SetId(value); return *this;}

    /*
     The streaming distribution's id.
    */
    inline UpdateStreamingDistribution2015_04_17Request& WithId(Aws::String&& value) { SetId(value); return *this;}

    /*
     The streaming distribution's id.
    */
    inline UpdateStreamingDistribution2015_04_17Request& WithId(const char* value) { SetId(value); return *this;}

    /*
     The value of the ETag header you received when retrieving the streaming distribution's configuration. For example: E2QWRUHAPOMQZL.
    */
    inline const Aws::String& GetIfMatch() const{ return m_ifMatch; }

    /*
     The value of the ETag header you received when retrieving the streaming distribution's configuration. For example: E2QWRUHAPOMQZL.
    */
    inline void SetIfMatch(const Aws::String& value) { m_ifMatchHasBeenSet = true; m_ifMatch = value; }

    /*
     The value of the ETag header you received when retrieving the streaming distribution's configuration. For example: E2QWRUHAPOMQZL.
    */
    inline void SetIfMatch(Aws::String&& value) { m_ifMatchHasBeenSet = true; m_ifMatch = value; }

    /*
     The value of the ETag header you received when retrieving the streaming distribution's configuration. For example: E2QWRUHAPOMQZL.
    */
    inline void SetIfMatch(const char* value) { m_ifMatchHasBeenSet = true; m_ifMatch.assign(value); }

    /*
     The value of the ETag header you received when retrieving the streaming distribution's configuration. For example: E2QWRUHAPOMQZL.
    */
    inline UpdateStreamingDistribution2015_04_17Request& WithIfMatch(const Aws::String& value) { SetIfMatch(value); return *this;}

    /*
     The value of the ETag header you received when retrieving the streaming distribution's configuration. For example: E2QWRUHAPOMQZL.
    */
    inline UpdateStreamingDistribution2015_04_17Request& WithIfMatch(Aws::String&& value) { SetIfMatch(value); return *this;}

    /*
     The value of the ETag header you received when retrieving the streaming distribution's configuration. For example: E2QWRUHAPOMQZL.
    */
    inline UpdateStreamingDistribution2015_04_17Request& WithIfMatch(const char* value) { SetIfMatch(value); return *this;}

  private:
    StreamingDistributionConfig m_streamingDistributionConfig;
    bool m_streamingDistributionConfigHasBeenSet;
    Aws::String m_id;
    bool m_idHasBeenSet;
    Aws::String m_ifMatch;
    bool m_ifMatchHasBeenSet;
  };

} // namespace Model
} // namespace CloudFront
} // namespace Aws
