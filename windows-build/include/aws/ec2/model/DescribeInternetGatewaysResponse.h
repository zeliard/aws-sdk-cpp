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
#include <aws/ec2/EC2_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/ec2/model/ResponseMetadata.h>
#include <aws/ec2/model/InternetGateway.h>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Xml
{
  class XmlDocument;
} // namespace Xml
} // namespace Utils
namespace EC2
{
namespace Model
{
  /*
    $shape.documentation
  */
  class AWS_EC2_API DescribeInternetGatewaysResponse
  {
  public:
    DescribeInternetGatewaysResponse();
    DescribeInternetGatewaysResponse(const AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);
    DescribeInternetGatewaysResponse& operator=(const AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);

    /*
     <p>Information about one or more Internet gateways.</p>
    */
    inline const Aws::Vector<InternetGateway>& GetInternetGateways() const{ return m_internetGateways; }

    /*
     <p>Information about one or more Internet gateways.</p>
    */
    inline void SetInternetGateways(const Aws::Vector<InternetGateway>& value) { m_internetGateways = value; }

    /*
     <p>Information about one or more Internet gateways.</p>
    */
    inline void SetInternetGateways(Aws::Vector<InternetGateway>&& value) { m_internetGateways = value; }

    /*
     <p>Information about one or more Internet gateways.</p>
    */
    inline DescribeInternetGatewaysResponse& WithInternetGateways(const Aws::Vector<InternetGateway>& value) { SetInternetGateways(value); return *this;}

    /*
     <p>Information about one or more Internet gateways.</p>
    */
    inline DescribeInternetGatewaysResponse& WithInternetGateways(Aws::Vector<InternetGateway>&& value) { SetInternetGateways(value); return *this;}

    /*
     <p>Information about one or more Internet gateways.</p>
    */
    inline DescribeInternetGatewaysResponse& AddInternetGateways(const InternetGateway& value) { m_internetGateways.push_back(value); return *this; }

    /*
     <p>Information about one or more Internet gateways.</p>
    */
    inline DescribeInternetGatewaysResponse& AddInternetGateways(InternetGateway&& value) { m_internetGateways.push_back(value); return *this; }

    
    inline const ResponseMetadata& GetResponseMetadata() const{ return m_responseMetadata; }

    
    inline void SetResponseMetadata(const ResponseMetadata& value) { m_responseMetadata = value; }

    
    inline void SetResponseMetadata(ResponseMetadata&& value) { m_responseMetadata = value; }

    
    inline DescribeInternetGatewaysResponse& WithResponseMetadata(const ResponseMetadata& value) { SetResponseMetadata(value); return *this;}

    
    inline DescribeInternetGatewaysResponse& WithResponseMetadata(ResponseMetadata&& value) { SetResponseMetadata(value); return *this;}

  private:
    Aws::Vector<InternetGateway> m_internetGateways;
    ResponseMetadata m_responseMetadata;
  };

} // namespace Model
} // namespace EC2
} // namespace Aws