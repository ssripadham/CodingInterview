/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
*/

public class Solution {
    
    private int CoinChangeHelper(int[] coins, int amount, int[] cache){

        if (amount == 0) return 0;
        
        if (cache[amount] != -1) {
            return cache[amount];
        }
        
        int minSoFar = int.MaxValue-1;
        for (int i = 0; i < coins.Length; ++i){
            if (amount >= coins[i]) {
                int val = CoinChangeHelper(coins,amount-coins[i], cache)+1;
                if (val < minSoFar) minSoFar = val;
           
            }
        }
        cache[amount] = minSoFar;
        
        return minSoFar;
        
    }
    
    public int CoinChange(int[] coins, int amount) {
        
        int[] cache = new int[amount+1];
        for (int i = 0; i <= amount; ++i) cache[i] = -1;
        
        int c =  CoinChangeHelper(coins, amount, cache);
        if (c == int.MaxValue-1) return -1;
        return c;
    }
}