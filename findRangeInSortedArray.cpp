#include <iostream>
#include <vector>
#include <climits>
#include <utility>

using namespace std;

pair<int,int> findRange(const vector<int> & v, int startIndex, int endIndex, int k) {
	
	if (startIndex > endIndex) return make_pair(INT_MAX,INT_MIN);

	if (startIndex == endIndex) 
		return (v[startIndex]==k) ? make_pair(startIndex, endIndex) : make_pair(INT_MAX,INT_MIN);

	if (v[startIndex] == v[endIndex] && v[startIndex] == k) return make_pair(startIndex,endIndex);

	int mid = (startIndex + endIndex)/2;

	pair<int,int> range;

	if (k < v[mid]) {
		range = findRange(v, startIndex, mid -1, k);
	} else if (k > v[mid]) {
		range = findRange(v, mid+1, endIndex, k);
	} else {
		// We know a[mid] = k
		pair<int,int> p1 = findRange(v, startIndex, mid-1,k);
		pair<int,int> p2 = findRange(v, mid+1, endIndex, k);
		range = make_pair(std::min(mid, p1.first),
						  std::max(p2.second, mid) );
	}

	return range;

}

int main() {

	vector<int> v = { 1, 1, 2, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 6, 6, 7, 8, 8, 9, 11};

	int n = 3;

	for (int n = 0; n < 15; ++n){
		pair<int,int> range = findRange(v, 0, v.size() -1, n);
		cout<<"Range for "<<n<< " is index "<<range.first<<" to "<<range.second<<endl;
	}
}