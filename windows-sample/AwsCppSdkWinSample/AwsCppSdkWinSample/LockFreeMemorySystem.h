#pragma once

#include <aws/core/utils/memory/MemorySystemInterface.h>
#include <aws/core/utils/memory/AWSMemory.h>

#define NOMINMAX
#include <Windows.h>

__declspec(align(MEMORY_ALLOCATION_ALIGNMENT))
struct MemAllocInfo : SLIST_ENTRY
{
	MemAllocInfo(int size) : mAllocSize(size), mExtraTag(-1)
	{}

	long mAllocSize; ///< MemAllocInfo�� ���Ե� ũ��
	long mExtraTag; ///< ��Ÿ �߰� ���� (��: Ÿ�� ���� �±� ���� ��)

}; ///< total 16 ����Ʈ

inline void* AttachMemAllocInfo(MemAllocInfo* header, int size)
{
	new (header)MemAllocInfo(size);
	return reinterpret_cast<void*>(++header);
}

inline MemAllocInfo* DetachMemAllocInfo(void* ptr)
{
	MemAllocInfo* header = reinterpret_cast<MemAllocInfo*>(ptr);
	--header;
	return header;
}

__declspec(align(MEMORY_ALLOCATION_ALIGNMENT))
class SmallSizeMemoryPool
{
public:
	SmallSizeMemoryPool(DWORD allocSize);

	MemAllocInfo* Pop();
	void Push(MemAllocInfo* ptr);


private:
	SLIST_HEADER mFreeList; ///< �ݵ�� ù��° ��ġ

	const DWORD mAllocSize;
	volatile long mAllocCount = 0;
};


class LockFreeMemorySystem : public Aws::Utils::Memory::MemorySystemInterface
{
public:

	LockFreeMemorySystem();
	virtual ~LockFreeMemorySystem() {}

	virtual void Begin() override;
	virtual void End() override;

	virtual void* AllocateMemory(std::size_t blockSize, std::size_t alignment, const char *allocationTag = nullptr) override;
	virtual void FreeMemory(void* memoryPtr) override;

private:
	enum Config
	{
		MAX_POOL_COUNT = 48,
		MAX_CHUNK_SIZE = 32768
	};

	/// ���ϴ� ũ���� �޸𸮸� ������ �ִ� Ǯ�� O(1) access�� ���� ���̺�
	SmallSizeMemoryPool* mSmallSizeMemoryPoolTable[MAX_CHUNK_SIZE + 1];
	
};