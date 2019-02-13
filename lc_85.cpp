/*
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
  
  
  ["1","0","1","0","0"],
  ["2","2","2","2","2"],
  ["3","3","3","4","6"],
  ["4","0","0","1","0"]
]

dp[i,j] += a[i+1,j] 
dp[i,j] += a[i, j+1]

1 1 = 2

1 1
0 1  = 2

0 1
1 1  = 2


1 1
1 1  = 4 

1 1 0
1 1 1 = 4  

1 1 1
1 1 1 =6
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(),0));
        
        dp[0][0] = matrix[0][0];
        int maximum = dp[0][0];
        for (int i = 1; i < matrix.size(); ++i) {
            dp[i][0] = dp[i-1][0];
            maximum = max(maximum, dp[i][0]);
        }
        
        for (int j = 1; j < matrix[0].size(); ++j) {
            dp[0][j] = dp[0][j-1];
            maximum = max(maximum, dp[0][j]);
        }
        
        for (int i = 2; i < matrix.size(); ++i){
            for (int j = 2; j < matrix[0].size(); ++j){
                if (matrix[i-1][j] == 1 && matrix[i][j-1] == 1 && matrix[i-1][j-1] == 1) {
                    //highest even + 2
                    int max1 = max(dp[i][j-1], dp[i-1][j]);
                    int num1 = (dp[i][j-1]%2 == 0)? dp[i][j-1]: 1;
                    int num2 = (dp[i-1][j]%2 == 0)? dp[i-1][j]: 1;
                    dp[i][j] = max(max(dp[i][j-1], dp[i-1][j]),max(num1, num2) + 2);
                    maximum = max(maximum, dp[i][j]);
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                    maximum = max(maximum, dp[i][j]);
                }
            }
        }
                
        return maximum;                      
                               
    }
};
