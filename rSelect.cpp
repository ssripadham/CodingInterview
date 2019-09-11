#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void swap(int & a, int & b){
	int tmp = a;
	a = b;
	b = tmp;
	//cout<<a<<" "<<b<<endl;
}



int partition(vector<int> & v, int start, int end){
	
	int pivot = end;
	//cout<<"Pivot:"<<v[pivot]<<endl;
	int i = start-1;
	for (int j = start; j < end; ++j) {

		if (v[j] <= v[pivot]) {
			i++;
			swap(v[i], v[j]); 
		}
	}
	swap(v[i+1],v[end]);
	//cout<<"Pos "<<i+1<<" "<<v[i+1]<<endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));cout<<endl;
	return i+1;
}


int select(vector<int> A,int p, int r, int i) {

	if (p == r) return A[p];

	int q = partition(A, p, r);

	int k = q - p + 1; //number of elements on lower side

	//cout<<"i="<<i<<" k"<<k<<endl;
	if (k == i) return A[q];
	else if (i < k) return select(A, p, q - 1, i);
	else return select(A,q+1,r,i-k);
} 
	



int main() {

	// 2  6 7  8  9  10
	//vector<int> v = { 7, 9, 2, 6, 10, 8 }
	vector<int> v = { 8, 16, 80, 55, 32, 8, 38, 40, 65, 18, 15, 45, 50, 38, 54, 52, 23, 74, 81, 42, 28, 16, 66, 35, 91, 36, 44, 9, 85, 58, 59, 49, 75, 20, 87, 60, 17, 11, 39, 62, 20, 17, 46, 26, 81, 92 };
	//cout<<partition(v, 0, v.size()-1)<<endl;
	cout<<select(v, 0, v.size()-1, 9 )<<endl;
	//copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
}