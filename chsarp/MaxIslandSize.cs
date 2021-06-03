/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/

public class Solution {
    public int MaxAreaOfIsland(int[][] grid) {
        
        int maxSoFar = 0;
        int count = 0;
        for (int i = 0; i < grid.Length; ++i) {
            for (int j = 0; j < grid[0].Length; ++j){
                if (grid[i][j] == 0) continue;
                count = 0;
                GetIslandSize(grid, i,j, ref count);
                maxSoFar = Math.Max(maxSoFar,count);
            }
        }
        return maxSoFar;
    }
    
    public void GetIslandSize(int[][]grid, int row, int col, ref int count){
    
        count++;
        grid[row][col] = 0;
        
        for (int dx = -1; dx <= +1; ++dx){
            for (int dy = -1; dy <= 1; ++dy){
                if (dx != 0 && dy != 0 || (dx == 0 && dy == 0)) continue;
                 if (row+dx < 0 || row+dx > grid.Length - 1 || col+dy < 0 || col+dy > grid[0].Length -1) {
                   continue;
                }       
                //Console.WriteLine($"{row+dx} {col+dy}");
                if (grid[row+dx][col+dy] == 1){
                    GetIslandSize(grid, row+dx, col+dy, ref count);
                }
            }
        }
        
    }
}
