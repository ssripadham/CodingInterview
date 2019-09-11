
#include <stack>
#include <map>
#include <utility>
#include <climits>
#include <iostream>

using  namespace std;


class MiniStack {

public:

	MiniStack(){
		myStack = new stack<int>();
		minStack = new stack<pair<int,int>>();
	}

	void push(int  val){
		if (minStack->empty()){
			minStack->push(make_pair(val, 0));
		} else {
			int minSoFar = minStack->top().first;

			if (val < minSoFar) {
				minStack->push(make_pair(val, myStack->size()));
			}
		}
		myStack->push(val);
	}

	int top(){
		myStack->top();
	}


	void pop() {

		if (myStack->empty()){
			return;
		}
		
		int topElem = myStack->top();

		int topElemInMinStack = minStack->top().first;

		if (topElemInMinStack == topElem){
			
			if (myStack->size() -1 <= minStack->top().second) {
				minStack->pop();
			}
		} 

		myStack->pop();
	}

	int minVal() {

		if (minStack->empty()){
			return INT_MIN;
		}
		return minStack->top().first;
	}

	bool isEmpty(){
		return myStack->empty();
	}

	~MiniStack() {
		delete myStack;
	}
	
private:

	stack<int> * myStack;
	stack<pair<int,int>> * minStack;

};

int main(){
	MiniStack s;
	s.push(8);
	s.push(2);
	s.push(1);
	s.push(1);
	s.push(1);
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	cout<<s.minVal()<<endl;
	return 1;
}

