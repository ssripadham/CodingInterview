/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/
public class Solution {
    private int ClimbStairsHelper(int n, int[] cache){
        
        if (n==0) {
            return 1;
        }
        
        if (n < 0) return 0;
        
        if (cache[n] != -1) return cache[n];
        
        cache[n] = ClimbStairsHelper(n-1, cache) 
            + ClimbStairsHelper(n-2, cache);
        return cache[n];
    }
    
    public int ClimbStairs(int n) {
        int[] cache = new int[n+1];
        for (int i = 0; i <= n; ++i){
            cache[i] = -1;
        }
        cache[0] = 0; cache[1]=1;
        return ClimbStairsHelper(n, cache);
    }
}
