/*
You are given coins of different denominations and a total amount of money.
 Write a function to compute the number of combinations that make up that amount.
  You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
 

Note:

You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
*/
  

/*
         5
    
   4 (1)       3(2)     2(3)
   
  3(1) 2(2) 1(3)
  
  2 (1)
  
  1(1)
  
  0(1)

*/

public class Solution {
    
    private int ChangeUtils(int amount, int[] coins, int index, int[,] cache){
    
        if (amount == 0) {
            return 1;
        }
        
       if (cache[amount,index] != -1) return cache[amount, index];
        
        int numWays = 0;
        for (int i = index; i < coins.Length; ++i){
            if (amount - coins[i] >= 0) {
                numWays += ChangeUtils(amount - coins[i], coins, i, cache);// Note i => Coin Reuse.
            }
        }
        
        cache[amount,index] = numWays;
        return numWays;
    }
    
    
    public int Change(int amount, int[] coins) {
        if (coins.Length == 0) return (amount == 0)?1:0;
        int[,] cache = new int[amount+1, coins.Length];
        
        for (int i = 0; i < cache.GetLength(0); i++)
        {
            for (int j = 0; j < cache.GetLength(1); j++) cache[i, j] = -1;
        }
        
        return ChangeUtils(amount, coins,0, cache);   
    }
}
