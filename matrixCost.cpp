#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMin(const vector<int> & v){

	vector< vector<int> > dp(v.size(), vector<int>(v.size()));
	int n = v.size();

	/*
	
	X X X X X
    - - - -   (0 to n-l+1)

    i = 0 , n = 5, l = 2


    XXX
    0  2
    l = j-i+1
    j = i + l - 1

	*/
    for (int i = 0; i < n; i++)
    	dp[i][i] = 0;

	for (int l = 2 ; l <= v.size(); l++) {
		for (int i = 0; i < n - l; ++i) {
			int j = i + l ;

			dp[i][j] = INT_MAX;
			for (int k = i+1; k < j ; ++k){

				int q = dp[i][k] + dp[i][k]+dp[k+1][j]+ v[i]*v[k]*v[j];
				dp[i][j] = std::min(q, dp[i][j]);
			}
		}
	}	

	return dp[0][v.size()-1];
}


int main() {
	
	vector<int> v = {2,3,6,4,5};

	cout<<findMin(v)<<endl;
}