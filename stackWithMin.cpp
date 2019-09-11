/*
  Implement a stack with push, pop and min in O(1)
*/

#include <stack>
#include <utility>

using namespace std;

template <typename T>
class mystack {
private:
	T data;
	stack<T,T> s;

public:
	T top();
	void push(T& data);
	void pop();
	T min();
	bool empty();
};


void push(T & data) {

	min = s.empty()? data : std::min(s.top().second(), data);	
	s.push(make_pair(data,min));

}

void pop() {
	if (s.empty()) return;
	s.pop();
}

T top(){
	return s.top().first;
}

T min() {
	return s.top().second;
}

bool empty() {
	return s.empty();
}