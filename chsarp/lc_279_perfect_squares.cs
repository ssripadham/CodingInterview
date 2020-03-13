/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

public class Solution {
    public int NumSquares(int n) {
        
        if (n < 0) return 0;
        int[] dp = new int[n+1];
        
        for (int k = 1; k <= n; ++k) dp[k] = Int32.MaxValue;
        
        dp[0] = 0; 
        
        for (int k = 1; k <= n; ++k){
            
            for(int j = 1; j*j <= k ; ++j){
                
                dp[k] = Math.Min(dp[k], 1+dp[k-j*j]);    
                
            }
            
        }
        
        return dp[n];
        
    }
}