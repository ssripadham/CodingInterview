/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/
public class Solution {
    public bool SearchMatrix(int[,] matrix, int target) {

        int numRow = matrix.GetLength(0);
        int numCol = matrix.GetLength(1);
        
        int r = 0;
        int c = numCol - 1;
        
        while (c >= 0 && r < numRow) {
            
            if (target == matrix[r,c])
                return true;
            
            if (target < matrix[r,c]){
                c--;
            } else {
                r++;
            }
        }
        
        return false;
    }
}

/*

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]


class Solution {
    int[][] matrix;
    int target;
    public boolean searchMatrix(int[][] matrix, int target) {
        this.matrix = matrix;
        this.target = target;
        if(matrix.length==0)
            return false;
        return helper(0, 0, matrix.length-1, matrix[0].length-1);
    }
    /**
    * @param x1, row coordinate of top left element of the matrix
    * @param y1, column coordinate of top left elemeent of the matrix
    * @param x2, row coordinate of bottom right element of the matrix
    * @param y2, column coordinate of bottom right element of the matrix
    */
    /* 
    private boolean helper(int x1, int y1, int x2, int y2){
        if(x2<x1 || y2<y1 || x1>=matrix.length || y1>=matrix[0].length || x2<0 || y2<0)
            return false;
        int mx = (x2-x1)/2+x1;
        int my = (y2-y1)/2+y1;
        // Check the middle element of the matrix, if not found, 
        // recursively call on sub matrices where
        // the value could still exist. 
        // You will realize that the resultant possible places will
        // form a L shape on the original matrix.
        // This L shape can be broken down into 2 matrices.
        // If number found in any of the 2 matrices, we return true.
        if(matrix[mx][my]==target)
            return true;
        else if(matrix[mx][my]<target){
            return helper(x1,my+1,x2,y2) || helper(mx+1,y1,x2,my);
        }else if(matrix[mx][my]>target){
            return helper(x1,y1,x2,my-1) || helper(x1,my,mx-1,y2);
        }else
            return false;
    }
}

         y1         my   my+1            y2   
x1    (x1,y1)            (x1,my+1)



mx             (mx,my)                  (mx,y2)
mx+1  (mx+1, y1)

                      
 x2            (x2,my)                   (x2,y2)
 */