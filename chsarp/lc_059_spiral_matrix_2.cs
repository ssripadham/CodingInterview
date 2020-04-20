/*

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

r,c

offset = n/2

offset -> 0 to n/2

Fill row 0 col + offset  to numCol-offset
Fill lastColumn (row+1)+offset to numRow - offset
Fill lastRow (numCol-1)-offset to col+offset
Fill firstRow (numRow-1)-offset to row+offset


0,0 0,1  0,2


*/

public class Solution {
    /*
    public int[][] GenerateMatrix(int n) {
        
        int[][] matrix = new int[n][];
        for (int i = 0; i < matrix.Length; ++i){
            matrix[i] = new int[n];
        }
        
        int count = 1;
        for (int offset = 0; offset <= n/2; ++ offset){
            
            int row = offset; //1
            for (int c = offset; c <= (n-1)-offset; ++c){
                matrix[row][c] = count++;
            }
            
            if (offset == n-1-offset) break;
            
            int col = (n-1)-offset;
            for (int r = 1+offset ; r < (n-1)-offset; ++r){
                matrix[r][col] = count++;
            }
            
            row = (n-1)-offset;//1
            for (int c = (n-1)-offset; c >= offset; --c){
                matrix[row][c] = count++;
            }
            
            col = offset;
            for (int r = (n-1)-1-offset ; r > offset; --r){
                matrix[r][col] = count++;
            }
            
        }
        return matrix;
    }*/

    public int[][] GenerateMatrix(int n) {
        int[][] matrix = new int[n][];
        for (int i = 0; i < matrix.Length; ++i){
            matrix[i] = new int[n];
        }
        if (n <= 0) return matrix;
        
        int num = 1, rowbegin = 0, rowend = n - 1, colbegin = 0, colend = n - 1;
        while (rowbegin <= rowend && colbegin <= colend) {
            for (int i = colbegin; i <= colend; i++) matrix[rowbegin][i] = num++;
            rowbegin++;
            
            for (int i = rowbegin; i <= rowend; i++) matrix[i][colend] = num++;
            colend--;
            
            for (int i = colend; i >= colbegin; i--) matrix[rowend][i] = num++;
            rowend--;
            
            for (int i = rowend; i >= rowbegin; i--) matrix[i][colbegin] = num++;
            colbegin++;
        }
        return matrix;
    }
}

