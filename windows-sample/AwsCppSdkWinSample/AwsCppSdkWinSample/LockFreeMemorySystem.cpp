#include "stdafx.h"
#include "LockFreeMemorySystem.h"

SmallSizeMemoryPool::SmallSizeMemoryPool(DWORD allocSize) : mAllocSize(allocSize)
{
	assert(allocSize > MEMORY_ALLOCATION_ALIGNMENT);
	InitializeSListHead(&mFreeList);
}

MemAllocInfo* SmallSizeMemoryPool::Pop()
{
	MemAllocInfo* mem = (MemAllocInfo*)InterlockedPopEntrySList(&mFreeList);
	if (nullptr == mem)
	{
		mem = reinterpret_cast<MemAllocInfo*>(_aligned_malloc(mAllocSize, MEMORY_ALLOCATION_ALIGNMENT));
	}
	else
	{
		assert(mem->mAllocSize == 0);
	}

	InterlockedIncrement(&mAllocCount);
	return mem;
}

void SmallSizeMemoryPool::Push(MemAllocInfo* ptr)
{
	InterlockedPushEntrySList(&mFreeList, (PSLIST_ENTRY)ptr);
	InterlockedDecrement(&mAllocCount);
}

/////////////////////////////////////////////////////////////////////

LockFreeMemorySystem::LockFreeMemorySystem()
{
	memset(mSmallSizeMemoryPoolTable, 0, sizeof(mSmallSizeMemoryPoolTable));
}

void LockFreeMemorySystem::Begin()
{
	int currIdx = 1;
	for (int i = 0; i <= MAX_POOL_COUNT; ++i)
	{
		int chunkSize = ((i % 4) + 4) << (1 + (i >> 2)); ///< my magic!

		if (chunkSize > MEMORY_ALLOCATION_ALIGNMENT && chunkSize % MEMORY_ALLOCATION_ALIGNMENT == 0)
		{
			auto newPool = new SmallSizeMemoryPool(chunkSize);
			while (currIdx <= chunkSize)
				mSmallSizeMemoryPoolTable[currIdx++] = newPool;
		}
	}
}

void LockFreeMemorySystem::End()
{
}

void* LockFreeMemorySystem::AllocateMemory(std::size_t blockSize, std::size_t alignment, const char *allocationTag)
{
	AWS_UNREFERENCED_PARAM(alignment);
	AWS_UNREFERENCED_PARAM(allocationTag);

	MemAllocInfo* header = nullptr;
	int realAllocSize = static_cast<int>(blockSize) + sizeof(MemAllocInfo);

	if (realAllocSize > MAX_CHUNK_SIZE)
	{
		header = reinterpret_cast<MemAllocInfo*>(_aligned_malloc(realAllocSize, MEMORY_ALLOCATION_ALIGNMENT));
	}
	else
	{
		header = mSmallSizeMemoryPoolTable[realAllocSize]->Pop();
	}

	return AttachMemAllocInfo(header, realAllocSize);
}

void LockFreeMemorySystem::FreeMemory(void* memoryPtr)
{
	MemAllocInfo* header = DetachMemAllocInfo(memoryPtr);

	long realAllocSize = InterlockedExchange(&header->mAllocSize, 0); ///< 두번 해제 체크 위해

	assert(realAllocSize > 0);

	if (realAllocSize > MAX_CHUNK_SIZE)
	{
		_aligned_free(header);
	}
	else
	{
		mSmallSizeMemoryPoolTable[realAllocSize]->Push(header);
	}
}