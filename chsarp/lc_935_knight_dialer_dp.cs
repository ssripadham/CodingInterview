/*
A chess knight can move as indicated in the chess diagram below:

This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes N-1 hops.  Each hop must be from one key to another numbered key.

Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing N digits total.

How many distinct numbers can you dial in this manner?

Since the answer may be large, output the answer modulo 10^9 + 7.

 

Example 1:

Input: 1
Output: 10
Example 2:

Input: 2
Output: 20
Example 3:

Input: 3
Output: 46
*/
public class Solution {
    public int KnightDialer(int N) {
        
        Dictionary<int,List<int>> d = new Dictionary<int, List<int>> {
            {0, new List<int>{4,6}},
            {1, new List<int>{8,6}},
            {2, new List<int>{7,9}},
            {3, new List<int>{4,8}},
            {4, new List<int>{3,9,0}},
            {5, new List<int>{}},
            {6, new List<int>{1,7,0}},
            {7, new List<int>{2,6}},
            {8, new List<int>{1,3}},
            {9, new List<int>{2,4}}
        };
        
        Dictionary<Tuple<int,int>, int> cache = new Dictionary< Tuple<int,int>, int>();
        
        int ret = 0;
        for (int root = 0;  root <= 9; ++root){
            ret += KnightDialerUtil(N, root, 1, d, cache);
            ret = ret % 1_000_000_007;
        }
        
        return ret;
    }
    
    private int KnightDialerUtil(int N, int root, int numTurns, Dictionary<int,List<int>> d, Dictionary<Tuple<int,int>, int> cache){
        
        if (numTurns == N){
            return 1;
        }
        
        Tuple<int,int> findKey = new Tuple<int,int>(root, numTurns);
        if (cache.ContainsKey(findKey)){
            int cached = cache[findKey];
            return cached;
        }

        int ret = 0;
        for (int i = 0; i < d[root].Count; ++i){
            ret += KnightDialerUtil(N, d[root][i], numTurns+1, d, cache);
            ret = ret % 1_000_000_007;
        }
        
        cache.Add(new Tuple<int,int>(root,numTurns), ret);
        return ret;
    }
}

