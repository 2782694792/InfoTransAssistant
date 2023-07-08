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
using workers_ptr = std::shared_ptr<std::vector<std::shared_ptr<worker_t>>>; // �洢
using task_t = std::function<void()>;

class worker_t final
{
public:
	worker_t() = delete;

	worker_t(workers_ptr workers, int work_num) : workers_(workers), work_num_(work_num), enable_(true)
	{
		thread_ = std::thread(&worker_t::execute, this);
		//thread_.detach();
		//std::async(std::launch::async, &worker_t::execute, this); // �첽����ʽ
	}

	~worker_t()
	{
	}

	void assign(const task_t& task) // �������񣬴洢��������
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

			task_t t = queue_.pop_front(); // ���٣�ִ���׸�����
			while (t != nullptr) // ѭ��ִ��������е�����
			{
				t();
				t = queue_.pop_front();
			}

			// ȷ���������Ƿ���ڿɹ����������
			bool no_task = std::all_of(workers_->begin(), workers_->end(), [](std::shared_ptr<worker_t> worker) {return worker->empty(); });
			if (no_task)
			{
                //std::cout<<"all tasks have been finished!"<<std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
				continue;
			}

			int rand_select = rand() % workers_->size(); // ������ģ�����������һ������
			if (workers_->at(rand_select) == nullptr)
				continue;

			t = workers_->at(rand_select)->steal(); // ִ�����һ������

			if (t != nullptr)
			{
				t();
			}
		}
	}

private:
	std::thread thread_; // �����߳�
	std::shared_ptr<std::vector<std::shared_ptr<worker_t>>> workers_; 
	std::thread::id thread_id_; // �߳� id
	sync_deque<task_t> queue_; // ������У�ÿһ����ҵ���ж�������γɶ���

	int work_num_;
	bool enable_;
};

#endif
