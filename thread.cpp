#include <iostream>
#include <thread>

using namespace std;
void someMethod(){
	cout<<"Hello"<<endl;
}

int main() {
	std::thread t1(someMethod);
	t1.join();
}