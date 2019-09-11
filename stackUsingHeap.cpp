/*
Implement a stack API using a heap
*/

#include <iostream>
#include <queue> //has priority_queue
#include <vector>
#include <utility>

using namespace std;

template <typename T>
class Compare {
public:
	bool operator()(const pair<int,T> & a, const pair<int,T> & b) const{
		return a.first < b.first;
	}

};

//Note: MyStack is derived from STL prioity_queue
template <typename T>
class MyStack :
	public priority_queue<pair<int,T> , vector<pair<int,T>>, Compare<T> > {
	private:
		typedef priority_queue<pair<int,T> , vector<pair<int,T>>, Compare<T> > PQ;
		int count;
	public:

		MyStack(){
			count = 0;
		}

		const T top() const {
			T ret = PQ::top().second;
			return ret;
		}

		void push(T data) {
			PQ::emplace(count++,data);
		}
		
		//Base class functionality
		/*void pop() {
			pq.pop();
			--count;
		}

		bool empty() {
			pq.empty();
		}
		*/
};


int main(){

	MyStack<int> s;
	s.push(2);
	s.push(4);
	s.push(11);
	s.push(7);

	cout<<s.top()<<endl; s.pop(); //7

	s.push(8);
	cout<<s.top()<<endl;s.pop();//8

	cout<<s.top()<<endl;//11

}