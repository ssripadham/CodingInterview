/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/
public class Solution {
    public IList<int> SpiralOrder(int[][] matrix) {
        
        IList<int> output = new List<int>();
        if (matrix == null || matrix.Length == 0) return output;
        if (matrix.Length ==1 ) return matrix[0];
        
        int rowStart = 0;
        int rowEnd = matrix.Length - 1;
        int colStart = 0;
        int colEnd = matrix[0].Length -1;
                
        while (rowStart <= rowEnd && colStart <= colEnd){
        
            for (int c = colStart; c <= colEnd; ++c){
                output.Add(matrix[rowStart][c]);
            }           
            ++rowStart;
            
            for (int r = rowStart; r <= rowEnd; ++r){
                output.Add(matrix[r][colEnd]);
            }
            --colEnd;
            
            //if (colStart >= colEnd) break;
            if (rowStart <= rowEnd) {    
                for (int c = colEnd; c >= colStart; --c){
                    output.Add(matrix[rowEnd][c]);
                }
                --rowEnd;
            }
            
            if (colStart <= colEnd){
                for (int r = rowEnd; r >= rowStart; --r){
                    output.Add(matrix[r][colStart]);
                }
                ++colStart;
            }
            
        }
        return output;
    }
}