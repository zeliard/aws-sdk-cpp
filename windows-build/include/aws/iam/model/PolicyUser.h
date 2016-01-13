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
#include <aws/iam/IAM_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSStreamFwd.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace Utils
{
namespace Xml
{
  class XmlNode;
} // namespace Xml
} // namespace Utils
namespace IAM
{
namespace Model
{
  /*
    <p>Contains information about a user that a managed policy is attached to.</p> <p>This data type is used as a response element in the <a>ListEntitiesForPolicy</a> action. </p> <p>For more information about managed policies, refer to <a href="http://docs.aws.amazon.com/IAM/latest/UserGuide/policies-managed-vs-inline.html">Managed Policies and Inline Policies</a> in the <i>Using IAM</i> guide. </p>
  */
  class AWS_IAM_API PolicyUser
  {
  public:
    PolicyUser();
    PolicyUser(const Aws::Utils::Xml::XmlNode& xmlNode);
    PolicyUser& operator=(const Aws::Utils::Xml::XmlNode& xmlNode);

    void OutputToStream(Aws::OStream& ostream, const char* location, unsigned index, const char* locationValue) const;
    void OutputToStream(Aws::OStream& oStream, const char* location) const;

    /*
     <p>The name (friendly name, not ARN) identifying the user.</p>
    */
    inline const Aws::String& GetUserName() const{ return m_userName; }

    /*
     <p>The name (friendly name, not ARN) identifying the user.</p>
    */
    inline void SetUserName(const Aws::String& value) { m_userNameHasBeenSet = true; m_userName = value; }

    /*
     <p>The name (friendly name, not ARN) identifying the user.</p>
    */
    inline void SetUserName(Aws::String&& value) { m_userNameHasBeenSet = true; m_userName = value; }

    /*
     <p>The name (friendly name, not ARN) identifying the user.</p>
    */
    inline void SetUserName(const char* value) { m_userNameHasBeenSet = true; m_userName.assign(value); }

    /*
     <p>The name (friendly name, not ARN) identifying the user.</p>
    */
    inline PolicyUser& WithUserName(const Aws::String& value) { SetUserName(value); return *this;}

    /*
     <p>The name (friendly name, not ARN) identifying the user.</p>
    */
    inline PolicyUser& WithUserName(Aws::String&& value) { SetUserName(value); return *this;}

    /*
     <p>The name (friendly name, not ARN) identifying the user.</p>
    */
    inline PolicyUser& WithUserName(const char* value) { SetUserName(value); return *this;}

  private:
    Aws::String m_userName;
    bool m_userNameHasBeenSet;
  };

} // namespace Model
} // namespace IAM
} // namespace Aws
