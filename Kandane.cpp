 /*
  Write a program to find maximum sum rectangle in give 2D matrix.
  Assume there is at least one positive number in the 2D matrix.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iterator>
#include <tuple>

using namespace std;

tuple<int,int,int> maxSubArray(vector<int> & v){
	
	vector<int> dp(v.size());

	dp[0] = v[0];
	int colStart = 0;
	int colEnd = 0;
	int bestSoFar = INT_MIN;
	for (int i=1; i<v.size();++i) {
		if (dp[i-1] + v[i] > 0) {
			dp[i] = dp[i-1] + v[i];
			if (dp[i] > bestSoFar) {
				bestSoFar = dp[i];
				colEnd = i;
			}
		} else {
			colStart = i;
		}

	}

	return make_tuple(bestSoFar,colStart, colEnd);
}

tuple<int,int,int,int,int> maxSumRectangularSubMatrix( vector<vector<int> > & v2d) {

	int numRow = v2d.size();
	int numCol = v2d[0].size();

	int maxSum = INT_MIN;
	int bestSum = INT_MIN;
	int rowLow, rowHigh, colLow, colHigh;

	for (int rowStart = 0; rowStart < numRow; ++rowStart) {

		//For every rowStart we will compute new max.        
        vector< int > tmpArray(numCol,0);	

		for (int rowEnd = rowStart; rowEnd < numRow; ++ rowEnd) {	
			for (int col = 0; col < numCol; ++ col) {
				tmpArray[col] = tmpArray[col] + v2d[rowEnd][col];
			}

			//Mark the rows where it beats the best
			tuple<int,int,int> kandane = maxSubArray(tmpArray);
			if (std::get<0>(kandane) > bestSum) {
				rowLow  = rowStart;
				rowHigh = rowEnd;
				bestSum = std::get<0>(kandane);
				colLow  = std::get<1>(kandane);
				colHigh = std::get<2>(kandane);
			}

		}
	}

	return std::make_tuple(bestSum,rowLow,colLow,rowHigh,colHigh);

}

int main() {

	vector<vector<int> > v2d = { { 4, 5, 6, -3, 2},	
							     { 1, 2, -7, -3, -3},
								 { 6, -6, 5, 4, -1},
	 							 {-1, -1, -2, 1, 3}
	 							};

	int rowLow, rowHigh;
	vector<vector<int>> v2d1 = {{1, 2},
	                            {2, 2}};							
	auto result = maxSumRectangularSubMatrix(v2d);
	cout<<"Best sum: "<<std::get<0>(result) <<" from ["<< std::get<1>(result)<<","<<std::get<2>(result)<<"]"
		<<" to ["<<std::get<3>(result)<<","<<std::get<4>(result)<<"]"<<endl;
}