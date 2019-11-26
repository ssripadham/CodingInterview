/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

Example 1:

Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
Note: You may assume that n is not less than 2 and not larger than 58.
*/
public class Solution {
    
    
    private int IntegerBreakUtil(int n, Dictionary<int,int> cache) {
    
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        if (cache.ContainsKey(n)) return cache[n];
        
        int pdt = -1;
        for (int i = 1; i <= n; ++i ){
                pdt = Math.Max(pdt, i * (n-i));
                pdt = Math.Max(pdt,i*IntegerBreakUtil(n-i, cache));
        }
        
        cache[n] = pdt;
    
        return pdt;
    
    }

    
    public int IntegerBreak(int n) {
        return IntegerBreakUtil(n, new Dictionary<int,int>());
    }
}