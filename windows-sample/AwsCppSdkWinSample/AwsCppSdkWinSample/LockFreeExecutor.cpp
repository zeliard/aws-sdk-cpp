#include "stdafx.h"

#include "LockFreeExecutor.h"

using namespace Aws::Utils::Threading;

LockFreeExecutor::LockFreeExecutor()
	: mStopRequested(false)
	, mWorkerThread([this]{RunExecutor(); }) ///< spawn a worker-thread
{
}

LockFreeExecutor::~LockFreeExecutor()
{
	mStopRequested = true;
	mWorkerThread.join();

	while (JobEntry* job = mJobQueue.Pop())
	{
		delete job;
	}
}


bool LockFreeExecutor::SubmitToThread(std::function<void()>&& fx)
{
	JobEntry* job = new JobEntry(std::move(fx));
	mJobQueue.Push(job);
	return true;
}

void LockFreeExecutor::RunExecutor()
{
	while (!mStopRequested)
	{
		if (JobEntry* job = mJobQueue.Pop())
		{
			job->mTask();
			delete job;
		}
		else
		{
			Sleep(1); ///< optional
		}
	}
}