#include <iostream>
#include <queue>

using namespace std;

//Maintain k largest element in a min heap (greater comparator)
int kthlargest(std::vector<int> v, int k){
	priority_queue<int, std::vector<int>, greater<int>> pq; //greater => min

	for (int i = 0; i < v.size(); ++i){

		if (i < k) {
			pq.push(v[i]);
		} else {
			if ( v[i] > pq.top() ) {
				//We want to keep track of elements larger
				//than what is on min heap.
				pq.pop();
				pq.push(v[i]);
			}

		}
	}


	//while (!pq.empty()){
	//	cout<< pq.top() <<" "; pq.pop();
	//}
	//cout<<endl;

	return pq.top();
}


int main() {

	vector<int> v = { 22, 37, 12, 9, 8, 2, 11, 18, 15, 10};
	int k = 4;
	cout<<"kth largest for k="<<k<<" is "<<kthlargest(v,k)<<endl;
}