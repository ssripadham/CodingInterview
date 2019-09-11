#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int maxDifference(vector < int > a) {

	if (a.size() == 1) return a[0];

    vector<int> dp(a.size()); //minimum found upto Index
    
    dp[0] = a[0];
    for (int i = 1; i < a.size(); ++i){
        dp[i] = std::min(dp[i-1], a[i]);
        cout<<dp[i]<<endl;
    }
    
    int maxdiff = INT_MIN;
    for (int i = 0; i < a.size(); ++i){
        maxdiff = std::max(maxdiff, a[i]-dp[i]);
    }
    
   
    return maxdiff;
}

int main() {
	
	vector<int> v = { -3, -2 };
	cout<<maxDifference(v)<<endl;
}