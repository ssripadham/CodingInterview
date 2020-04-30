/*
A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [rows, cols], which means the matrix is rows * cols.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.
*/

/**
 * // This is BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *     public int Get(int x, int y) {}
 *     public IList<int> Dimensions() {}
 * }
 */

class Solution {
    public int LeftMostColumnWithOne(BinaryMatrix binaryMatrix){
        
        if (binaryMatrix == null) return 0;
        IList<int> dim = binaryMatrix.Dimensions();
        if (dim[0] == 0 || dim[1] == 0) return -1;
        int numRow = dim[0];
        int numCol = dim[1];
        
        int lowCol = 0;
        int highCol = numCol - 1;
        
        int result = -1;
        while (lowCol <= highCol){
         
            int midCol = lowCol + (highCol - lowCol)/2;
            
            bool found = false;
            for (int row = 0; row < numRow; ++row) {
                if (binaryMatrix.Get(row,midCol) == 1){
                    highCol = midCol - 1;
                    result = midCol;
                    found = true;
                    break;
                }
            }
            
            if (found == false){
                lowCol = midCol+1;
            }
            
        }
        
        return result;
    }
}

//midlist = [all row indices]
//Get the middle element in each col. 
//If is one add it to a list
//If none binary search to right
//If list.Length = 1 return mid  num
