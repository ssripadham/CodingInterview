/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/

public class Solution {
    
    private void Assign(string[] board, int row, int col){
        char[] charArr = board[row].ToCharArray();
        charArr[col] = 'Q';
        board[row] = new string(charArr);
    }
    
    private void UnAssign(string[] board, int row, int col){
        char[] charArr = board[row].ToCharArray();
        charArr[col] = '.';
        board[row] = new string(charArr);
    }
    
    private bool isUpperDiagSafe(string[] board, int row, int col){
        int maxRow = board.Length;
        int maxCol = board[0].Length;
        for (int r = row, c = col; r >= 0 && c < maxCol; --r, ++c){
            if (board[r][c] == 'Q') return false;
        }
        return true;
    }
    
    private bool isLowerDiagSafe(string[] board, int row, int col){
        int maxRow = board.Length;
        int maxCol = board[0].Length;
        for (int r = row, c = col; r >= 0 && c >= 0; --r, --c){
            if (board[r][c] == 'Q'){
               return false; 
            } 
        }
        return true;
    }
    
    private bool isRowSafe(string[] board, int row, int col){
        int maxCol = board[0].Length;
        for (int c = 0; c < maxCol; ++c){
            if (board[row][c] == 'Q') return false;
        }
        return true;
    }
    
    private bool isColSafe(string[] board, int row, int col){
        int maxRow = board.Length;
        for (int r = 0; r < maxRow; ++r){
            if (board[r][col] == 'Q') return false;
        }
        return true;
    }
    
    private bool isSafe(string[] board, int row, int col){
        return isColSafe(board, row, col) && isUpperDiagSafe(board, row, col) && isLowerDiagSafe(board, row, col);
    }
        
    private bool SolveQueenUtil(int n, IList<IList<string>> output, string[] board, int row){
    
        if (row == n){
            output.Add(new List<string>(board));
            return true;
        }
        
        for (int col = 0; col < n; ++col){
            
            if (!isSafe(board, row, col)) continue;
            Assign(board, row, col);
            
            SolveQueenUtil(n, output, board, row+1);
            
            UnAssign(board, row, col);
            
            
        }
        return false;
    }
    
    
    public IList<IList<string>> SolveNQueens(int n) {
        IList<IList<string>> output = new List<IList<string>>();
        
        string emptyRow = new string('.',n);
        string[] board = new string[n];
        for(int row = 0; row < board.Length; ++row){
            board[row] = new string(emptyRow.ToCharArray());
        }
        SolveQueenUtil(n, output, board, 0);
        return output;
    }
}
