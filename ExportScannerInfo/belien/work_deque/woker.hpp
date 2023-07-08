#ifndef BELIEN_WOKER_HPP
#define BELIEN_WOKER_HPP

#include <thread>
#include <memory>
#include <vector>
#include <functional>
#include <algorithm>
#include <future>
#include "sync_deque.hpp"
using namespace belien::syncdeque;

class worker_t;
using workers_ptr = std::shared_ptr<std::vector<std::shared_ptr<worker_t>>>; // 存储
using task_t = std::function<void()>;

class worker_t final
{
public:
	worker_t() = delete;

	worker_t(workers_ptr workers, int work_num) : workers_(workers), work_num_(work_num), enable_(true)
	{
		thread_ = std::thread(&worker_t::execute, this);
		//thread_.detach();
		//std::async(std::launch::async, &worker_t::execute, this); // 异步任务方式
	}

	~worker_t()
	{
	}

	void assign(const task_t& task) // 分配任务，存储到队列中
	{
		queue_.push_front(task);
	}

	task_t steal()
	{
		return queue_.pop_back();
	}

	bool empty()
	{
		return queue_.empty();
	}

	void join()
	{
		enable_ = false;
		thread_.join();
	}

private:

	void execute()
	{
		thread_id_ = std::this_thread::get_id();

		while (enable_)
		{
			if (work_num_ != workers_->size())
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
				continue;
			}

			task_t t = queue_.pop_front(); // （再）执行首个任务
			while (t != nullptr) // 循环执行完队列中的任务
			{
				t();
				t = queue_.pop_front();
			}

			// 确认容器中是否存在可工作任务队列
			bool no_task = std::all_of(workers_->begin(), workers_->end(), [](std::shared_ptr<worker_t> worker) {return worker->empty(); });
			if (no_task)
			{
                //std::cout<<"all tasks have been finished!"<<std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
				continue;
			}

			int rand_select = rand() % workers_->size(); // 存在则模拟随机运行下一个队列
			if (workers_->at(rand_select) == nullptr)
				continue;

			t = workers_->at(rand_select)->steal(); // 执行最后一个任务

			if (t != nullptr)
			{
				t();
			}
		}
	}

private:
	std::thread thread_; // 工作线程
	std::shared_ptr<std::vector<std::shared_ptr<worker_t>>> workers_; 
	std::thread::id thread_id_; // 线程 id
	sync_deque<task_t> queue_; // 任务队列，每一个作业者有多个任务，形成队列

	int work_num_;
	bool enable_;
};

#endif
