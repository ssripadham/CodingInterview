#include <thread>

using namespace std;

template<typename T>
class threaded_queue{
	conditional_variable cv;
	mutex    m;
	queue<T> q;

	threaded_queue(const threaded_queue & q1) {
		std::lock_guard<std::mutex> lg(m);
		q = q1;
	}

	void push(T val) {
		std::lock_guard<std::mutex> lg(m);
		q.push(m);
		cv.notify_one();
	}

	void pop(T & val) {
		std::unique_lock<std::mutex> ul;
		cv.wait(ul(m), [this](){!q.empty()} );
		val = q.front();
		q.pop();
	}
};
