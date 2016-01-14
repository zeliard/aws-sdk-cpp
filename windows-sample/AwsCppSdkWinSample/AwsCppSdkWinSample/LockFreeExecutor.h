#pragma once

#include <functional>
#include <atomic>
#include <memory>
#include <thread>
#include <chrono>
#include <assert.h>

#include <aws/core/utils/threading/Executor.h>
#include "ObjectPool.h"


struct NodeEntry
{
	NodeEntry() : mNext(nullptr) {}
	NodeEntry* volatile mNext;
};

struct JobEntry : public ObjectPool<JobEntry>
{
	JobEntry(std::function<void()>&& job) : mTask(std::move(job)) {}
	virtual ~JobEntry() {}

	NodeEntry mNodeEntry;

	std::function<void()> mTask;
};


class JobQueue
{
public:
	JobQueue() : mHead(&mStub), mTail(&mStub)
	{
		mOffset = offsetof(struct JobEntry, mNodeEntry);
	}
	~JobQueue() {}

	/// mutiple produce
	void Push(JobEntry* newData)
	{
		NodeEntry* prevNode = (NodeEntry*)InterlockedExchangePointer((volatile PVOID*)&mHead, (void*)&(newData->mNodeEntry));

		prevNode->mNext = &(newData->mNodeEntry);
	}

	/// single consume
	JobEntry* Pop()
	{
		NodeEntry* tail = mTail;
		NodeEntry* next = tail->mNext;

		if (tail == &mStub)
		{
			/// in case of empty
			if (nullptr == next)
				return nullptr;

			/// first pop
			mTail = next;
			tail = next;
			next = next->mNext;
		}

		/// in most cases...
		if (next)
		{
			mTail = next;

			return reinterpret_cast<JobEntry*>(reinterpret_cast<int64_t>(tail)-mOffset);
		}

		NodeEntry* head = mHead;
		if (tail != head)
			return nullptr;

		/// last pop
		mStub.mNext = nullptr;

		NodeEntry* prevNode = (NodeEntry*)InterlockedExchangePointer((volatile PVOID*)&mHead, (void*)&mStub);

		prevNode->mNext = &mStub;

		next = tail->mNext;
		if (next)
		{
			mTail = next;

			return reinterpret_cast<JobEntry*>(reinterpret_cast<int64_t>(tail)-mOffset);
		}

		return nullptr;
	}


private:

	NodeEntry* volatile mHead;

	NodeEntry*			mTail;
	NodeEntry			mStub;

	int64_t				mOffset;
};



class LockFreeExecutor : public Aws::Utils::Threading::Executor
{
public:
	LockFreeExecutor();
	~LockFreeExecutor();

protected:
	bool SubmitToThread(std::function<void()>&&) override; ///< Push a task (multi-produce)

private:
	void RunExecutor(); ///< Run (single-consume)

private:
	bool mStopRequested;

	JobQueue mJobQueue;
	std::thread mWorkerThread;
};

