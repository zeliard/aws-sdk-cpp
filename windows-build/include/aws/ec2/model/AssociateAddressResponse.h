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
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/ec2/model/ResponseMetadata.h>

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
  class AWS_EC2_API AssociateAddressResponse
  {
  public:
    AssociateAddressResponse();
    AssociateAddressResponse(const AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);
    AssociateAddressResponse& operator=(const AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);

    /*
     <p>[EC2-VPC] The ID that represents the association of the Elastic IP address with an instance.</p>
    */
    inline const Aws::String& GetAssociationId() const{ return m_associationId; }

    /*
     <p>[EC2-VPC] The ID that represents the association of the Elastic IP address with an instance.</p>
    */
    inline void SetAssociationId(const Aws::String& value) { m_associationId = value; }

    /*
     <p>[EC2-VPC] The ID that represents the association of the Elastic IP address with an instance.</p>
    */
    inline void SetAssociationId(Aws::String&& value) { m_associationId = value; }

    /*
     <p>[EC2-VPC] The ID that represents the association of the Elastic IP address with an instance.</p>
    */
    inline void SetAssociationId(const char* value) { m_associationId.assign(value); }

    /*
     <p>[EC2-VPC] The ID that represents the association of the Elastic IP address with an instance.</p>
    */
    inline AssociateAddressResponse& WithAssociationId(const Aws::String& value) { SetAssociationId(value); return *this;}

    /*
     <p>[EC2-VPC] The ID that represents the association of the Elastic IP address with an instance.</p>
    */
    inline AssociateAddressResponse& WithAssociationId(Aws::String&& value) { SetAssociationId(value); return *this;}

    /*
     <p>[EC2-VPC] The ID that represents the association of the Elastic IP address with an instance.</p>
    */
    inline AssociateAddressResponse& WithAssociationId(const char* value) { SetAssociationId(value); return *this;}

    
    inline const ResponseMetadata& GetResponseMetadata() const{ return m_responseMetadata; }

    
    inline void SetResponseMetadata(const ResponseMetadata& value) { m_responseMetadata = value; }

    
    inline void SetResponseMetadata(ResponseMetadata&& value) { m_responseMetadata = value; }

    
    inline AssociateAddressResponse& WithResponseMetadata(const ResponseMetadata& value) { SetResponseMetadata(value); return *this;}

    
    inline AssociateAddressResponse& WithResponseMetadata(ResponseMetadata&& value) { SetResponseMetadata(value); return *this;}

  private:
    Aws::String m_associationId;
    ResponseMetadata m_responseMetadata;
  };

} // namespace Model
} // namespace EC2
} // namespace Aws