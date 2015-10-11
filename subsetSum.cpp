/*
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/
*/

#include <iostream>
#include <vector>

using namespace std;

bool isSubSetSum(vector<int> & v, int sum, int index) {

	if (sum == 0) return true;
	if (sum < 0) return false;
	if (index == v.size()) return false;

	//Include - Exclude principle
	return isSubSetSum(v, sum, index+1) || isSubSetSum(v, sum - v[index], index+1);

}

int main() {
	vector<int> v = {3,34,4,12,5,2};
	cout<<isSubSetSum(v,45,0)<<endl;
}