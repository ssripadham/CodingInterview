/*
Given a distance ‘dist, count total number of ways to cover the distance with 1, 2 and 3 steps.
http://www.geeksforgeeks.org/count-number-of-ways-to-cover-a-distance/
*/

#include <iostream>
#include <vector>

using namespace std;
int howManyWays(int distance){

	if (distance == 0) return 1;
	if (distance < 0) return 0;
	return howManyWays(distance - 1) + howManyWays(distance -2) + howManyWays(distance - 3);
}

int howManyWaysDP(int dist){

	vector<int> dp(dist+1,0);

	dp[0] = 1;

	for (int i = 1; i <= dist; ++i) {

		if (i-1 >= 0) {
			dp[i] += dp[i-1];
		}

		if (i-2 >= 0) {
			dp[i] += dp[i-2];
		}
		if (i-3 >= 0) {
			dp[i] += dp[i-3];
		}
	}

	return dp[dist];
}

int main() {
	int n = 4;
	cout<<"Number of ways to cover "<<n<<" steps is "<<howManyWaysDP(n)<<" ways."<<endl;
	cout<<"Number of ways (DP) to cover "<<n<<" steps is "<<howManyWaysDP(n)<<" ways."<<endl;
}