/*
On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).

A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.

 

Example:

Input: 3, 2, 0, 0
Output: 0.0625
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
 

Note:

N will be between 1 and 25.
K will be between 0 and 100.
The knight always initially starts on the board.
*/
public class Solution {
    public double KnightProbability(int N, int K, int r, int c) {
        Dictionary< Tuple<int,int,int>, double> cache = new Dictionary< Tuple<int,int,int>, double>();
        return (KPUtil(N, K, r, c, 0, cache));
    }
    
    private double KPUtil(int N, int K, int r, int c, int moves, Dictionary<Tuple<int, int, int>, double> cache){
         if (r < 0 || r >= N || c < 0 || c >= N) return 0;
        
        if (moves == K){
            //Console.WriteLine($"{moves} {r} {c}");
            return 1.0;            
        }
    
        Tuple<int,int,int> findTuple = new Tuple<int,int,int>(r,c,moves);
        
        if (cache.ContainsKey(findTuple)){
            double cached = cache[findTuple];
            return cached;
        }
        
        double result = 0;
        for (int dr = -2; dr<= 2; ++dr){
            for (int dc = -2; dc <= +2; ++dc){
                
                if (Math.Abs(dr*dc) != 2) continue;
                result += KPUtil(N,K,r+dr,c+dc, moves+1, cache)/8;
            }
        }
        
        cache.Add(new Tuple<int,int,int>(r,c,moves), result);
        return result;
    }
}

