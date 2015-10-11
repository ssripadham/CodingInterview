#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <iterator>
using namespace std;

int howManyCoins(std::vector<int> & v, int total){

	if (total <= 0) return 0;

	int min = INT_MAX;
	for (int i = 0; i < v.size(); ++i){
		min = std::min(min,1+howManyCoins(v, total - v[i]));
	}

	return min;
}

int howManyCoinsDP(std::vector<int> v, int Total) {

	vector<int> dp(Total+1);

	dp[0] = 0;
	for (int t=1; t<=Total; ++t) {
		dp[t] = INT_MAX;
	}
	

	int min = INT_MAX;
	for (int t = 1; t <= Total ; ++t) {
	  for (int i = 0; i < v.size(); ++i){
		if (t - v[i] >= 0)
			dp[t] = std::min(dp[t], 1+dp[t - v[i]]);
		}
	}

	//std::copy(dp.begin(), dp.end(), ostream_iterator<int>(cout," "));
	return dp[Total];
}

int main() {

	std::vector<int> v = {1,2,3};

	cout<<"Minimum number of coins "<<howManyCoins(v,12)<<endl;
	cout<<"Minimum number of coins by DP "<<howManyCoinsDP(v,12)<<endl;
	
}
