/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/
public class Solution {
    public int MaximalSquare(char[][] matrix) {
        if (matrix == null || matrix.Length == 0 || matrix[0].Length == 0) return 0;
        
        int[,] dp = new int[matrix.Length+1, matrix[0].Length+1];
        
        int max_so_far = 0;
        for (int i = 1; i <= matrix.Length; i++){
            for (int j = 1; j <= matrix[0].Length; ++j){
                
                if (matrix[i-1][j-1] == '1'){
                    dp[i,j] = Math.Min(dp[i-1,j-1],Math.Min(dp[i,j-1], dp[i-1,j]))+1;
                    max_so_far = Math.Max(max_so_far, dp[i,j]);
                }
            }
        }
        return max_so_far*max_so_far;
    }
}
