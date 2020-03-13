/*
/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

public class Solution {
    public int NumIslands(char[][] grid) {
        
        
        int numRows = grid.Length;
        if (numRows == 0) return 0;
        int numCols = grid[0].Length;
        
        if (numCols == 0) return 0;
        
        int count = 0;
        
        for (int r = 0; r < numRows; ++r){
            for (int c = 0; c < numCols; ++ c){
                if (grid[r][c] == '1'){
                    count++;
                    dfs(grid,r,c);
                }
            }
        }
            
        return count;
    }
    
    private void dfs(char[][] grid, int r, int c){
        int numRow = grid.Length;
        int numCol = grid[0].Length;
        
        if (r < 0 || r >= numRow || c < 0 || c >= numCol) return ;
        if (grid[r][c] == '0') return;
        grid[r][c] = '0';
        dfs(grid, r-1, c);
        dfs(grid, r+1, c);
        dfs(grid, r, c-1);
        dfs(grid, r, c+1);
    }
    
}