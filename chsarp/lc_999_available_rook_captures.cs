/*
On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares, white bishops, and black pawns.  These are given as characters 'R', '.', 'B', and 'p' respectively. Uppercase characters represent white pieces, and lowercase characters represent black pieces.

The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, east, west, and south), then moves in that direction until it chooses to stop, reaches the edge of the board, or captures an opposite colored pawn by moving to the same square it occupies.  Also, rooks cannot move into the same square as other friendly bishops.

Return the number of pawns the rook can capture in one move.
*/
public class Solution {
    public int NumRookCaptures(char[][] board) {
        
        int numRow = board.Length;
        int numCol = board[0].Length;
        
        int row = -1;
        int col = -1;
        for (int r1 = 0; r1 < numRow; ++r1){
         
            for (int c1=0; c1 < numCol; ++c1){
                if (board[r1][c1]=='R'){
                    row = r1;
                    col = c1;
                    break;
                }
            }
        }
        
        int ans = 0;
        int r = row+1;
        while (r < numRow){
            if (board[r][col] == 'B') break;
            if (board[r][col] == 'p') { ++ans; break; }
            ++r;
        }
        
        r = row-1;
        while (r >= 0){
            if (board[r][col] == 'B') break;
            if (board[r][col] == 'p') {++ans; break;}
            --r;
        }
        
        int c = col+1;
        while (c < numCol){
            if (board[row][c] == 'B') break;
            if (board[row][c] == 'p') {++ans; break;}
            ++c;
        }
        
        c = col-1;
        while (c >= 0){
            if (board[row][c] == 'B') break;
            if (board[row][c] == 'p') {++ans; break;}
            --c;
        }
        
        return ans;
        
    }
}