#ifndef BELIEN_SYNC_DEQUE_HPP
#define BELIEN_SYNC_DEQUE_HPP

#include <deque>
#include <mutex>

namespace belien
{
	namespace syncdeque
	{
		template<class T>
		class sync_deque
		{
		public:
			sync_deque() = default;
			~sync_deque() = default;

			void push_front(const T &val) // LIFO
			{
				std::unique_lock<std::mutex> l(mtx_);
				deque_.push_front(val);
			}

			bool empty()
			{
				//std::unique_lock<std::mutex> l(mtx_);
				return deque_.empty();
			}

			T pop_front()
			{
				mtx_.lock();

				if (deque_.empty())
				{
					mtx_.unlock();
					return nullptr;
				}

				T val = deque_.front();
				deque_.pop_front();

				mtx_.unlock();

				return val;
			}

			T pop_back() // FIFO，删除并返回最后一个元素
			{
				if (!mtx_.try_lock())
					return nullptr;

				if (deque_.empty())
				{
					mtx_.unlock();
					return nullptr;
				}

				T val = deque_.back();
				deque_.pop_back();

				mtx_.unlock();

				return val;
			}

		private:
			std::deque<T> deque_;
			std::mutex mtx_;
		};
	}
}
#endif
