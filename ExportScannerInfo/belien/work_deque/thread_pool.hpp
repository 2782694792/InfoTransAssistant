#ifndef BELIEN_THREADPOOL_HPP
#define BELIEN_THREADPOOL_HPP

#include "woker.hpp"

#define MAX_THREAD_COUNT 20

class thread_pool
{
public:
	thread_pool(size_t thread_num = std::thread::hardware_concurrency())
	{
		if (thread_num > MAX_THREAD_COUNT)
		{

		}

		workers_ = std::make_shared<std::vector<std::shared_ptr<worker_t>>>();
		for (size_t i = 0; i < thread_num; i++)
		{
			auto worker = std::make_shared<worker_t>(workers_, thread_num);
			workers_->push_back(worker);
		}
	}

	~thread_pool()
	{
		for (auto worker : *workers_)
		{
			worker->join();
		}

		workers_->clear();
	}

	void add_task(const task_t& task)
	{
		auto worker = get_rand_worker();
		worker->assign(task); // 为作业者分配任务
	}

private:
	std::shared_ptr<worker_t> get_rand_worker()
	{
		int i = rand() % workers_->size();
		return workers_->at(i); // 随机一个作业者
	}

	workers_ptr workers_; // 作业向量（集）
};
#endif
