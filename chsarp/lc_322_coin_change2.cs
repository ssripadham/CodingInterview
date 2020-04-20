/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/
public class Solution {
    public int CoinChange(int[] coins, int amount) {
        int[] dp = new int[amount+1];
        dp[0] = 0;
        for (int i = 1; i < amount+1; ++i ){
            dp[i] = Int32.MaxValue; //dp[2] = max
            for (int j = 0; j < coins.Length; ++j){
                if (i >= coins[j]){ //2
                   dp[i] = Math.Min(dp[i], dp[i-coins[j]] != Int32.MaxValue? dp[i-coins[j]]+1 :dp[i-coins[j]]);
                }
            }
        }
        return (dp[amount] == Int32.MaxValue)? -1: dp[amount];
    }
}

/*
dp[0] = 0  
dp[1] = dp[1-1] + 1 = 1
dp[2] = min(dp[2-1], dp[2-2], dp[2-5])+1=1;  //min(2,1) = 1

dp[11] = ?
*/