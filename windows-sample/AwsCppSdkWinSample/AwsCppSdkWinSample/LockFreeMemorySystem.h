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

	long mAllocSize; ///< MemAllocInfo가 포함된 크기
	long mExtraTag; ///< 기타 추가 정보 (예: 타입 관련 태그 정보 등)

}; ///< total 16 바이트

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
	SLIST_HEADER mFreeList; ///< 반드시 첫번째 위치

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

	/// 원하는 크기의 메모리를 가지고 있는 풀에 O(1) access를 위한 테이블
	SmallSizeMemoryPool* mSmallSizeMemoryPoolTable[MAX_CHUNK_SIZE + 1];
	
};