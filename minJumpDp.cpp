#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void reconstructPath(int start, int end, vector<int> & p){
	
	if (start == end) {
		cout << start ;
		return;
	}

	reconstructPath(start, p[end], p);

	cout<<" -> "<<end;
}

int findMinimumJumps( const vector<int> & v){
	
	vector<int> dp(v.size(), INT_MAX);
	vector<int> p(v.size(),0);

	dp[0] = 0; p[0] = 0;

	for (int i = 1; i < v.size(); ++i){
		for (int j = 0; j < i; ++j) {
			if (j+v[j] >= i) {
				if (dp[j]+1 < dp[i]) {
					dp[i] = dp[j]+1;
					p[i] = j;
				}
			}
		}
	}

	reconstructPath(0, v.size()-1, p);
	return dp[v.size()-1];
}

int main() {
	vector<int> v = { 2,3,1,1,2,4,2,0,1,1};
	cout<<endl<<findMinimumJumps(v)<<endl;
}