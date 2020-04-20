/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
public class Solution {
    public int MinPathSum(int[][] grid) {
        
        if (grid.Length == 0|| grid[0].Length == 0) return -1;
        
        int[][] dp = new int[grid.Length][];
        
        for (int i = 0; i < grid.Length; ++i){
            dp[i] = new int[grid[0].Length];
        }
        
        dp[0][0] = grid[0][0];
        
        for (int i = 0; i < grid.Length; ++i){
            for (int j = 0; j < grid[0].Length; ++j){
                if (i == 0 && j == 0) continue;

                dp[i][j] = Math.Min((i-1 >= 0)?dp[i-1][j]:Int32.MaxValue, (j-1 >= 0)?dp[i][j-1]:Int32.MaxValue) + grid[i][j];
                
                //Console.WriteLine($"{dp[i][j]}");
            }
            //Console.WriteLine();
        }
        
        return dp[dp.Length - 1][dp[0].Length - 1];
    }
}
