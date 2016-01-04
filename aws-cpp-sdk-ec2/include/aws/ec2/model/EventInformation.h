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
namespace EC2
{
namespace Model
{
  /*
    <p>Describes a Spot fleet event.</p>
  */
  class AWS_EC2_API EventInformation
  {
  public:
    EventInformation();
    EventInformation(const Aws::Utils::Xml::XmlNode& xmlNode);
    EventInformation& operator=(const Aws::Utils::Xml::XmlNode& xmlNode);

    void OutputToStream(Aws::OStream& ostream, const char* location, unsigned index, const char* locationValue) const;
    void OutputToStream(Aws::OStream& oStream, const char* location) const;

    /*
     <p>The ID of the instance. This information is available only for <code>instanceChange</code> events.</p>
    */
    inline const Aws::String& GetInstanceId() const{ return m_instanceId; }

    /*
     <p>The ID of the instance. This information is available only for <code>instanceChange</code> events.</p>
    */
    inline void SetInstanceId(const Aws::String& value) { m_instanceIdHasBeenSet = true; m_instanceId = value; }

    /*
     <p>The ID of the instance. This information is available only for <code>instanceChange</code> events.</p>
    */
    inline void SetInstanceId(Aws::String&& value) { m_instanceIdHasBeenSet = true; m_instanceId = value; }

    /*
     <p>The ID of the instance. This information is available only for <code>instanceChange</code> events.</p>
    */
    inline void SetInstanceId(const char* value) { m_instanceIdHasBeenSet = true; m_instanceId.assign(value); }

    /*
     <p>The ID of the instance. This information is available only for <code>instanceChange</code> events.</p>
    */
    inline EventInformation& WithInstanceId(const Aws::String& value) { SetInstanceId(value); return *this;}

    /*
     <p>The ID of the instance. This information is available only for <code>instanceChange</code> events.</p>
    */
    inline EventInformation& WithInstanceId(Aws::String&& value) { SetInstanceId(value); return *this;}

    /*
     <p>The ID of the instance. This information is available only for <code>instanceChange</code> events.</p>
    */
    inline EventInformation& WithInstanceId(const char* value) { SetInstanceId(value); return *this;}

    /*
     <p>The event.</p> <p>The following are the <code>error</code> events.</p> <ul> <li> <p><code>iamFleetRoleInvalid</code> - Spot fleet did not have the required permissions either to launch or terminate an instance.</p> </li> <li> <p><code>spotFleetRequestConfigurationInvalid</code> - The configuration is not valid. For more information, see the description.</p> </li> <li> <p><code>spotInstanceCountLimitExceeded</code> - You've reached the limit on the number of Spot Instances that you can launch.</p> </li> </ul> <p>The following are the <code>fleetRequestChange</code> events.</p> <ul> <li> <p><code>active</code> - The Spot fleet has been validated and Amazon EC2 is attempting to maintain the target number of running Spot Instances.</p> </li> <li> <p><code>cancelled</code> - The Spot fleet is canceled and has no running Spot Instances. The Spot fleet will be deleted two days after its instances were terminated.</p> </li> <li> <p><code>cancelled_running</code> - The Spot fleet is canceled and will not launch additional Spot Instances, but its existing Spot Instances will continue to run until they are interrupted or terminated.</p> </li> <li> <p><code>cancelled_terminating</code> - The Spot fleet is canceled and its Spot Instances are terminating.</p> </li> <li> <p><code>expired</code> - The Spot fleet request has expired. A subsequent event indicates that the instances were terminated, if the request was created with <code>terminateInstancesWithExpiration</code> set.</p> </li> <li> <p><code>price_update</code> - The bid price for a launch configuration was adjusted because it was too high. This change is permanent.</p> </li> <li> <p><code>submitted</code> - The Spot fleet request is being evaluated and Amazon EC2 is preparing to launch the target number of Spot Instances.</p> </li> </ul> <p>The following are the <code>instanceChange</code> events.</p> <ul> <li> <p><code>launched</code> - A bid was fulfilled and a new instance was launched.</p> </li> <li> <p><code>terminated</code> - An instance was terminated by the user.</p> </li> </ul>
    */
    inline const Aws::String& GetEventSubType() const{ return m_eventSubType; }

    /*
     <p>The event.</p> <p>The following are the <code>error</code> events.</p> <ul> <li> <p><code>iamFleetRoleInvalid</code> - Spot fleet did not have the required permissions either to launch or terminate an instance.</p> </li> <li> <p><code>spotFleetRequestConfigurationInvalid</code> - The configuration is not valid. For more information, see the description.</p> </li> <li> <p><code>spotInstanceCountLimitExceeded</code> - You've reached the limit on the number of Spot Instances that you can launch.</p> </li> </ul> <p>The following are the <code>fleetRequestChange</code> events.</p> <ul> <li> <p><code>active</code> - The Spot fleet has been validated and Amazon EC2 is attempting to maintain the target number of running Spot Instances.</p> </li> <li> <p><code>cancelled</code> - The Spot fleet is canceled and has no running Spot Instances. The Spot fleet will be deleted two days after its instances were terminated.</p> </li> <li> <p><code>cancelled_running</code> - The Spot fleet is canceled and will not launch additional Spot Instances, but its existing Spot Instances will continue to run until they are interrupted or terminated.</p> </li> <li> <p><code>cancelled_terminating</code> - The Spot fleet is canceled and its Spot Instances are terminating.</p> </li> <li> <p><code>expired</code> - The Spot fleet request has expired. A subsequent event indicates that the instances were terminated, if the request was created with <code>terminateInstancesWithExpiration</code> set.</p> </li> <li> <p><code>price_update</code> - The bid price for a launch configuration was adjusted because it was too high. This change is permanent.</p> </li> <li> <p><code>submitted</code> - The Spot fleet request is being evaluated and Amazon EC2 is preparing to launch the target number of Spot Instances.</p> </li> </ul> <p>The following are the <code>instanceChange</code> events.</p> <ul> <li> <p><code>launched</code> - A bid was fulfilled and a new instance was launched.</p> </li> <li> <p><code>terminated</code> - An instance was terminated by the user.</p> </li> </ul>
    */
    inline void SetEventSubType(const Aws::String& value) { m_eventSubTypeHasBeenSet = true; m_eventSubType = value; }

    /*
     <p>The event.</p> <p>The following are the <code>error</code> events.</p> <ul> <li> <p><code>iamFleetRoleInvalid</code> - Spot fleet did not have the required permissions either to launch or terminate an instance.</p> </li> <li> <p><code>spotFleetRequestConfigurationInvalid</code> - The configuration is not valid. For more information, see the description.</p> </li> <li> <p><code>spotInstanceCountLimitExceeded</code> - You've reached the limit on the number of Spot Instances that you can launch.</p> </li> </ul> <p>The following are the <code>fleetRequestChange</code> events.</p> <ul> <li> <p><code>active</code> - The Spot fleet has been validated and Amazon EC2 is attempting to maintain the target number of running Spot Instances.</p> </li> <li> <p><code>cancelled</code> - The Spot fleet is canceled and has no running Spot Instances. The Spot fleet will be deleted two days after its instances were terminated.</p> </li> <li> <p><code>cancelled_running</code> - The Spot fleet is canceled and will not launch additional Spot Instances, but its existing Spot Instances will continue to run until they are interrupted or terminated.</p> </li> <li> <p><code>cancelled_terminating</code> - The Spot fleet is canceled and its Spot Instances are terminating.</p> </li> <li> <p><code>expired</code> - The Spot fleet request has expired. A subsequent event indicates that the instances were terminated, if the request was created with <code>terminateInstancesWithExpiration</code> set.</p> </li> <li> <p><code>price_update</code> - The bid price for a launch configuration was adjusted because it was too high. This change is permanent.</p> </li> <li> <p><code>submitted</code> - The Spot fleet request is being evaluated and Amazon EC2 is preparing to launch the target number of Spot Instances.</p> </li> </ul> <p>The following are the <code>instanceChange</code> events.</p> <ul> <li> <p><code>launched</code> - A bid was fulfilled and a new instance was launched.</p> </li> <li> <p><code>terminated</code> - An instance was terminated by the user.</p> </li> </ul>
    */
    inline void SetEventSubType(Aws::String&& value) { m_eventSubTypeHasBeenSet = true; m_eventSubType = value; }

    /*
     <p>The event.</p> <p>The following are the <code>error</code> events.</p> <ul> <li> <p><code>iamFleetRoleInvalid</code> - Spot fleet did not have the required permissions either to launch or terminate an instance.</p> </li> <li> <p><code>spotFleetRequestConfigurationInvalid</code> - The configuration is not valid. For more information, see the description.</p> </li> <li> <p><code>spotInstanceCountLimitExceeded</code> - You've reached the limit on the number of Spot Instances that you can launch.</p> </li> </ul> <p>The following are the <code>fleetRequestChange</code> events.</p> <ul> <li> <p><code>active</code> - The Spot fleet has been validated and Amazon EC2 is attempting to maintain the target number of running Spot Instances.</p> </li> <li> <p><code>cancelled</code> - The Spot fleet is canceled and has no running Spot Instances. The Spot fleet will be deleted two days after its instances were terminated.</p> </li> <li> <p><code>cancelled_running</code> - The Spot fleet is canceled and will not launch additional Spot Instances, but its existing Spot Instances will continue to run until they are interrupted or terminated.</p> </li> <li> <p><code>cancelled_terminating</code> - The Spot fleet is canceled and its Spot Instances are terminating.</p> </li> <li> <p><code>expired</code> - The Spot fleet request has expired. A subsequent event indicates that the instances were terminated, if the request was created with <code>terminateInstancesWithExpiration</code> set.</p> </li> <li> <p><code>price_update</code> - The bid price for a launch configuration was adjusted because it was too high. This change is permanent.</p> </li> <li> <p><code>submitted</code> - The Spot fleet request is being evaluated and Amazon EC2 is preparing to launch the target number of Spot Instances.</p> </li> </ul> <p>The following are the <code>instanceChange</code> events.</p> <ul> <li> <p><code>launched</code> - A bid was fulfilled and a new instance was launched.</p> </li> <li> <p><code>terminated</code> - An instance was terminated by the user.</p> </li> </ul>
    */
    inline void SetEventSubType(const char* value) { m_eventSubTypeHasBeenSet = true; m_eventSubType.assign(value); }

    /*
     <p>The event.</p> <p>The following are the <code>error</code> events.</p> <ul> <li> <p><code>iamFleetRoleInvalid</code> - Spot fleet did not have the required permissions either to launch or terminate an instance.</p> </li> <li> <p><code>spotFleetRequestConfigurationInvalid</code> - The configuration is not valid. For more information, see the description.</p> </li> <li> <p><code>spotInstanceCountLimitExceeded</code> - You've reached the limit on the number of Spot Instances that you can launch.</p> </li> </ul> <p>The following are the <code>fleetRequestChange</code> events.</p> <ul> <li> <p><code>active</code> - The Spot fleet has been validated and Amazon EC2 is attempting to maintain the target number of running Spot Instances.</p> </li> <li> <p><code>cancelled</code> - The Spot fleet is canceled and has no running Spot Instances. The Spot fleet will be deleted two days after its instances were terminated.</p> </li> <li> <p><code>cancelled_running</code> - The Spot fleet is canceled and will not launch additional Spot Instances, but its existing Spot Instances will continue to run until they are interrupted or terminated.</p> </li> <li> <p><code>cancelled_terminating</code> - The Spot fleet is canceled and its Spot Instances are terminating.</p> </li> <li> <p><code>expired</code> - The Spot fleet request has expired. A subsequent event indicates that the instances were terminated, if the request was created with <code>terminateInstancesWithExpiration</code> set.</p> </li> <li> <p><code>price_update</code> - The bid price for a launch configuration was adjusted because it was too high. This change is permanent.</p> </li> <li> <p><code>submitted</code> - The Spot fleet request is being evaluated and Amazon EC2 is preparing to launch the target number of Spot Instances.</p> </li> </ul> <p>The following are the <code>instanceChange</code> events.</p> <ul> <li> <p><code>launched</code> - A bid was fulfilled and a new instance was launched.</p> </li> <li> <p><code>terminated</code> - An instance was terminated by the user.</p> </li> </ul>
    */
    inline EventInformation& WithEventSubType(const Aws::String& value) { SetEventSubType(value); return *this;}

    /*
     <p>The event.</p> <p>The following are the <code>error</code> events.</p> <ul> <li> <p><code>iamFleetRoleInvalid</code> - Spot fleet did not have the required permissions either to launch or terminate an instance.</p> </li> <li> <p><code>spotFleetRequestConfigurationInvalid</code> - The configuration is not valid. For more information, see the description.</p> </li> <li> <p><code>spotInstanceCountLimitExceeded</code> - You've reached the limit on the number of Spot Instances that you can launch.</p> </li> </ul> <p>The following are the <code>fleetRequestChange</code> events.</p> <ul> <li> <p><code>active</code> - The Spot fleet has been validated and Amazon EC2 is attempting to maintain the target number of running Spot Instances.</p> </li> <li> <p><code>cancelled</code> - The Spot fleet is canceled and has no running Spot Instances. The Spot fleet will be deleted two days after its instances were terminated.</p> </li> <li> <p><code>cancelled_running</code> - The Spot fleet is canceled and will not launch additional Spot Instances, but its existing Spot Instances will continue to run until they are interrupted or terminated.</p> </li> <li> <p><code>cancelled_terminating</code> - The Spot fleet is canceled and its Spot Instances are terminating.</p> </li> <li> <p><code>expired</code> - The Spot fleet request has expired. A subsequent event indicates that the instances were terminated, if the request was created with <code>terminateInstancesWithExpiration</code> set.</p> </li> <li> <p><code>price_update</code> - The bid price for a launch configuration was adjusted because it was too high. This change is permanent.</p> </li> <li> <p><code>submitted</code> - The Spot fleet request is being evaluated and Amazon EC2 is preparing to launch the target number of Spot Instances.</p> </li> </ul> <p>The following are the <code>instanceChange</code> events.</p> <ul> <li> <p><code>launched</code> - A bid was fulfilled and a new instance was launched.</p> </li> <li> <p><code>terminated</code> - An instance was terminated by the user.</p> </li> </ul>
    */
    inline EventInformation& WithEventSubType(Aws::String&& value) { SetEventSubType(value); return *this;}

    /*
     <p>The event.</p> <p>The following are the <code>error</code> events.</p> <ul> <li> <p><code>iamFleetRoleInvalid</code> - Spot fleet did not have the required permissions either to launch or terminate an instance.</p> </li> <li> <p><code>spotFleetRequestConfigurationInvalid</code> - The configuration is not valid. For more information, see the description.</p> </li> <li> <p><code>spotInstanceCountLimitExceeded</code> - You've reached the limit on the number of Spot Instances that you can launch.</p> </li> </ul> <p>The following are the <code>fleetRequestChange</code> events.</p> <ul> <li> <p><code>active</code> - The Spot fleet has been validated and Amazon EC2 is attempting to maintain the target number of running Spot Instances.</p> </li> <li> <p><code>cancelled</code> - The Spot fleet is canceled and has no running Spot Instances. The Spot fleet will be deleted two days after its instances were terminated.</p> </li> <li> <p><code>cancelled_running</code> - The Spot fleet is canceled and will not launch additional Spot Instances, but its existing Spot Instances will continue to run until they are interrupted or terminated.</p> </li> <li> <p><code>cancelled_terminating</code> - The Spot fleet is canceled and its Spot Instances are terminating.</p> </li> <li> <p><code>expired</code> - The Spot fleet request has expired. A subsequent event indicates that the instances were terminated, if the request was created with <code>terminateInstancesWithExpiration</code> set.</p> </li> <li> <p><code>price_update</code> - The bid price for a launch configuration was adjusted because it was too high. This change is permanent.</p> </li> <li> <p><code>submitted</code> - The Spot fleet request is being evaluated and Amazon EC2 is preparing to launch the target number of Spot Instances.</p> </li> </ul> <p>The following are the <code>instanceChange</code> events.</p> <ul> <li> <p><code>launched</code> - A bid was fulfilled and a new instance was launched.</p> </li> <li> <p><code>terminated</code> - An instance was terminated by the user.</p> </li> </ul>
    */
    inline EventInformation& WithEventSubType(const char* value) { SetEventSubType(value); return *this;}

    /*
     <p>The description of the event.</p>
    */
    inline const Aws::String& GetEventDescription() const{ return m_eventDescription; }

    /*
     <p>The description of the event.</p>
    */
    inline void SetEventDescription(const Aws::String& value) { m_eventDescriptionHasBeenSet = true; m_eventDescription = value; }

    /*
     <p>The description of the event.</p>
    */
    inline void SetEventDescription(Aws::String&& value) { m_eventDescriptionHasBeenSet = true; m_eventDescription = value; }

    /*
     <p>The description of the event.</p>
    */
    inline void SetEventDescription(const char* value) { m_eventDescriptionHasBeenSet = true; m_eventDescription.assign(value); }

    /*
     <p>The description of the event.</p>
    */
    inline EventInformation& WithEventDescription(const Aws::String& value) { SetEventDescription(value); return *this;}

    /*
     <p>The description of the event.</p>
    */
    inline EventInformation& WithEventDescription(Aws::String&& value) { SetEventDescription(value); return *this;}

    /*
     <p>The description of the event.</p>
    */
    inline EventInformation& WithEventDescription(const char* value) { SetEventDescription(value); return *this;}

  private:
    Aws::String m_instanceId;
    bool m_instanceIdHasBeenSet;
    Aws::String m_eventSubType;
    bool m_eventSubTypeHasBeenSet;
    Aws::String m_eventDescription;
    bool m_eventDescriptionHasBeenSet;
  };

} // namespace Model
} // namespace EC2
} // namespace Aws
