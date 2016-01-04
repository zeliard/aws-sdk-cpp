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
#include <aws/ec2/model/SnapshotState.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/ec2/model/ResponseMetadata.h>
#include <aws/ec2/model/Tag.h>

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
    <p>Describes a snapshot.</p>
  */
  class AWS_EC2_API CreateSnapshotResponse
  {
  public:
    CreateSnapshotResponse();
    CreateSnapshotResponse(const AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);
    CreateSnapshotResponse& operator=(const AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);

    /*
     <p>The ID of the snapshot.</p>
    */
    inline const Aws::String& GetSnapshotId() const{ return m_snapshotId; }

    /*
     <p>The ID of the snapshot.</p>
    */
    inline void SetSnapshotId(const Aws::String& value) { m_snapshotId = value; }

    /*
     <p>The ID of the snapshot.</p>
    */
    inline void SetSnapshotId(Aws::String&& value) { m_snapshotId = value; }

    /*
     <p>The ID of the snapshot.</p>
    */
    inline void SetSnapshotId(const char* value) { m_snapshotId.assign(value); }

    /*
     <p>The ID of the snapshot.</p>
    */
    inline CreateSnapshotResponse& WithSnapshotId(const Aws::String& value) { SetSnapshotId(value); return *this;}

    /*
     <p>The ID of the snapshot.</p>
    */
    inline CreateSnapshotResponse& WithSnapshotId(Aws::String&& value) { SetSnapshotId(value); return *this;}

    /*
     <p>The ID of the snapshot.</p>
    */
    inline CreateSnapshotResponse& WithSnapshotId(const char* value) { SetSnapshotId(value); return *this;}

    /*
     <p>The ID of the volume.</p>
    */
    inline const Aws::String& GetVolumeId() const{ return m_volumeId; }

    /*
     <p>The ID of the volume.</p>
    */
    inline void SetVolumeId(const Aws::String& value) { m_volumeId = value; }

    /*
     <p>The ID of the volume.</p>
    */
    inline void SetVolumeId(Aws::String&& value) { m_volumeId = value; }

    /*
     <p>The ID of the volume.</p>
    */
    inline void SetVolumeId(const char* value) { m_volumeId.assign(value); }

    /*
     <p>The ID of the volume.</p>
    */
    inline CreateSnapshotResponse& WithVolumeId(const Aws::String& value) { SetVolumeId(value); return *this;}

    /*
     <p>The ID of the volume.</p>
    */
    inline CreateSnapshotResponse& WithVolumeId(Aws::String&& value) { SetVolumeId(value); return *this;}

    /*
     <p>The ID of the volume.</p>
    */
    inline CreateSnapshotResponse& WithVolumeId(const char* value) { SetVolumeId(value); return *this;}

    /*
     <p>The snapshot state.</p>
    */
    inline const SnapshotState& GetState() const{ return m_state; }

    /*
     <p>The snapshot state.</p>
    */
    inline void SetState(const SnapshotState& value) { m_state = value; }

    /*
     <p>The snapshot state.</p>
    */
    inline void SetState(SnapshotState&& value) { m_state = value; }

    /*
     <p>The snapshot state.</p>
    */
    inline CreateSnapshotResponse& WithState(const SnapshotState& value) { SetState(value); return *this;}

    /*
     <p>The snapshot state.</p>
    */
    inline CreateSnapshotResponse& WithState(SnapshotState&& value) { SetState(value); return *this;}

    /*
     <p>The time stamp when the snapshot was initiated.</p>
    */
    inline double GetStartTime() const{ return m_startTime; }

    /*
     <p>The time stamp when the snapshot was initiated.</p>
    */
    inline void SetStartTime(double value) { m_startTime = value; }

    /*
     <p>The time stamp when the snapshot was initiated.</p>
    */
    inline CreateSnapshotResponse& WithStartTime(double value) { SetStartTime(value); return *this;}

    /*
     <p>The progress of the snapshot, as a percentage.</p>
    */
    inline const Aws::String& GetProgress() const{ return m_progress; }

    /*
     <p>The progress of the snapshot, as a percentage.</p>
    */
    inline void SetProgress(const Aws::String& value) { m_progress = value; }

    /*
     <p>The progress of the snapshot, as a percentage.</p>
    */
    inline void SetProgress(Aws::String&& value) { m_progress = value; }

    /*
     <p>The progress of the snapshot, as a percentage.</p>
    */
    inline void SetProgress(const char* value) { m_progress.assign(value); }

    /*
     <p>The progress of the snapshot, as a percentage.</p>
    */
    inline CreateSnapshotResponse& WithProgress(const Aws::String& value) { SetProgress(value); return *this;}

    /*
     <p>The progress of the snapshot, as a percentage.</p>
    */
    inline CreateSnapshotResponse& WithProgress(Aws::String&& value) { SetProgress(value); return *this;}

    /*
     <p>The progress of the snapshot, as a percentage.</p>
    */
    inline CreateSnapshotResponse& WithProgress(const char* value) { SetProgress(value); return *this;}

    /*
     <p>The AWS account ID of the EBS snapshot owner.</p>
    */
    inline const Aws::String& GetOwnerId() const{ return m_ownerId; }

    /*
     <p>The AWS account ID of the EBS snapshot owner.</p>
    */
    inline void SetOwnerId(const Aws::String& value) { m_ownerId = value; }

    /*
     <p>The AWS account ID of the EBS snapshot owner.</p>
    */
    inline void SetOwnerId(Aws::String&& value) { m_ownerId = value; }

    /*
     <p>The AWS account ID of the EBS snapshot owner.</p>
    */
    inline void SetOwnerId(const char* value) { m_ownerId.assign(value); }

    /*
     <p>The AWS account ID of the EBS snapshot owner.</p>
    */
    inline CreateSnapshotResponse& WithOwnerId(const Aws::String& value) { SetOwnerId(value); return *this;}

    /*
     <p>The AWS account ID of the EBS snapshot owner.</p>
    */
    inline CreateSnapshotResponse& WithOwnerId(Aws::String&& value) { SetOwnerId(value); return *this;}

    /*
     <p>The AWS account ID of the EBS snapshot owner.</p>
    */
    inline CreateSnapshotResponse& WithOwnerId(const char* value) { SetOwnerId(value); return *this;}

    /*
     <p>The description for the snapshot.</p>
    */
    inline const Aws::String& GetDescription() const{ return m_description; }

    /*
     <p>The description for the snapshot.</p>
    */
    inline void SetDescription(const Aws::String& value) { m_description = value; }

    /*
     <p>The description for the snapshot.</p>
    */
    inline void SetDescription(Aws::String&& value) { m_description = value; }

    /*
     <p>The description for the snapshot.</p>
    */
    inline void SetDescription(const char* value) { m_description.assign(value); }

    /*
     <p>The description for the snapshot.</p>
    */
    inline CreateSnapshotResponse& WithDescription(const Aws::String& value) { SetDescription(value); return *this;}

    /*
     <p>The description for the snapshot.</p>
    */
    inline CreateSnapshotResponse& WithDescription(Aws::String&& value) { SetDescription(value); return *this;}

    /*
     <p>The description for the snapshot.</p>
    */
    inline CreateSnapshotResponse& WithDescription(const char* value) { SetDescription(value); return *this;}

    /*
     <p>The size of the volume, in GiB.</p>
    */
    inline long GetVolumeSize() const{ return m_volumeSize; }

    /*
     <p>The size of the volume, in GiB.</p>
    */
    inline void SetVolumeSize(long value) { m_volumeSize = value; }

    /*
     <p>The size of the volume, in GiB.</p>
    */
    inline CreateSnapshotResponse& WithVolumeSize(long value) { SetVolumeSize(value); return *this;}

    /*
     <p>The AWS account alias (for example, <code>amazon</code>, <code>self</code>) or AWS account ID that owns the snapshot.</p>
    */
    inline const Aws::String& GetOwnerAlias() const{ return m_ownerAlias; }

    /*
     <p>The AWS account alias (for example, <code>amazon</code>, <code>self</code>) or AWS account ID that owns the snapshot.</p>
    */
    inline void SetOwnerAlias(const Aws::String& value) { m_ownerAlias = value; }

    /*
     <p>The AWS account alias (for example, <code>amazon</code>, <code>self</code>) or AWS account ID that owns the snapshot.</p>
    */
    inline void SetOwnerAlias(Aws::String&& value) { m_ownerAlias = value; }

    /*
     <p>The AWS account alias (for example, <code>amazon</code>, <code>self</code>) or AWS account ID that owns the snapshot.</p>
    */
    inline void SetOwnerAlias(const char* value) { m_ownerAlias.assign(value); }

    /*
     <p>The AWS account alias (for example, <code>amazon</code>, <code>self</code>) or AWS account ID that owns the snapshot.</p>
    */
    inline CreateSnapshotResponse& WithOwnerAlias(const Aws::String& value) { SetOwnerAlias(value); return *this;}

    /*
     <p>The AWS account alias (for example, <code>amazon</code>, <code>self</code>) or AWS account ID that owns the snapshot.</p>
    */
    inline CreateSnapshotResponse& WithOwnerAlias(Aws::String&& value) { SetOwnerAlias(value); return *this;}

    /*
     <p>The AWS account alias (for example, <code>amazon</code>, <code>self</code>) or AWS account ID that owns the snapshot.</p>
    */
    inline CreateSnapshotResponse& WithOwnerAlias(const char* value) { SetOwnerAlias(value); return *this;}

    /*
     <p>Any tags assigned to the snapshot.</p>
    */
    inline const Aws::Vector<Tag>& GetTags() const{ return m_tags; }

    /*
     <p>Any tags assigned to the snapshot.</p>
    */
    inline void SetTags(const Aws::Vector<Tag>& value) { m_tags = value; }

    /*
     <p>Any tags assigned to the snapshot.</p>
    */
    inline void SetTags(Aws::Vector<Tag>&& value) { m_tags = value; }

    /*
     <p>Any tags assigned to the snapshot.</p>
    */
    inline CreateSnapshotResponse& WithTags(const Aws::Vector<Tag>& value) { SetTags(value); return *this;}

    /*
     <p>Any tags assigned to the snapshot.</p>
    */
    inline CreateSnapshotResponse& WithTags(Aws::Vector<Tag>&& value) { SetTags(value); return *this;}

    /*
     <p>Any tags assigned to the snapshot.</p>
    */
    inline CreateSnapshotResponse& AddTags(const Tag& value) { m_tags.push_back(value); return *this; }

    /*
     <p>Any tags assigned to the snapshot.</p>
    */
    inline CreateSnapshotResponse& AddTags(Tag&& value) { m_tags.push_back(value); return *this; }

    /*
     <p>Indicates whether the snapshot is encrypted.</p>
    */
    inline bool GetEncrypted() const{ return m_encrypted; }

    /*
     <p>Indicates whether the snapshot is encrypted.</p>
    */
    inline void SetEncrypted(bool value) { m_encrypted = value; }

    /*
     <p>Indicates whether the snapshot is encrypted.</p>
    */
    inline CreateSnapshotResponse& WithEncrypted(bool value) { SetEncrypted(value); return *this;}

    /*
     <p>The full ARN of the AWS Key Management Service (AWS KMS) customer master key (CMK) that was used to protect the volume encryption key for the parent volume.</p>
    */
    inline const Aws::String& GetKmsKeyId() const{ return m_kmsKeyId; }

    /*
     <p>The full ARN of the AWS Key Management Service (AWS KMS) customer master key (CMK) that was used to protect the volume encryption key for the parent volume.</p>
    */
    inline void SetKmsKeyId(const Aws::String& value) { m_kmsKeyId = value; }

    /*
     <p>The full ARN of the AWS Key Management Service (AWS KMS) customer master key (CMK) that was used to protect the volume encryption key for the parent volume.</p>
    */
    inline void SetKmsKeyId(Aws::String&& value) { m_kmsKeyId = value; }

    /*
     <p>The full ARN of the AWS Key Management Service (AWS KMS) customer master key (CMK) that was used to protect the volume encryption key for the parent volume.</p>
    */
    inline void SetKmsKeyId(const char* value) { m_kmsKeyId.assign(value); }

    /*
     <p>The full ARN of the AWS Key Management Service (AWS KMS) customer master key (CMK) that was used to protect the volume encryption key for the parent volume.</p>
    */
    inline CreateSnapshotResponse& WithKmsKeyId(const Aws::String& value) { SetKmsKeyId(value); return *this;}

    /*
     <p>The full ARN of the AWS Key Management Service (AWS KMS) customer master key (CMK) that was used to protect the volume encryption key for the parent volume.</p>
    */
    inline CreateSnapshotResponse& WithKmsKeyId(Aws::String&& value) { SetKmsKeyId(value); return *this;}

    /*
     <p>The full ARN of the AWS Key Management Service (AWS KMS) customer master key (CMK) that was used to protect the volume encryption key for the parent volume.</p>
    */
    inline CreateSnapshotResponse& WithKmsKeyId(const char* value) { SetKmsKeyId(value); return *this;}

    
    inline const ResponseMetadata& GetResponseMetadata() const{ return m_responseMetadata; }

    
    inline void SetResponseMetadata(const ResponseMetadata& value) { m_responseMetadata = value; }

    
    inline void SetResponseMetadata(ResponseMetadata&& value) { m_responseMetadata = value; }

    
    inline CreateSnapshotResponse& WithResponseMetadata(const ResponseMetadata& value) { SetResponseMetadata(value); return *this;}

    
    inline CreateSnapshotResponse& WithResponseMetadata(ResponseMetadata&& value) { SetResponseMetadata(value); return *this;}

  private:
    Aws::String m_snapshotId;
    Aws::String m_volumeId;
    SnapshotState m_state;
    double m_startTime;
    Aws::String m_progress;
    Aws::String m_ownerId;
    Aws::String m_description;
    long m_volumeSize;
    Aws::String m_ownerAlias;
    Aws::Vector<Tag> m_tags;
    bool m_encrypted;
    Aws::String m_kmsKeyId;
    ResponseMetadata m_responseMetadata;
  };

} // namespace Model
} // namespace EC2
} // namespace Aws