/*
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
*/
public class Solution {
    public int MinCostClimbingStairs(int[] cost) {

        if (cost.Length < 2) return -1;
        
        int[] dp = new int[cost.Length+1];
        
        
        dp[0] = cost[0];//10
        dp[1] = cost[1];//15
        
        //10 15 30 15
        
        for (int i = 2; i < dp.Length; ++i ){
            int addend = (i < cost.Length)?cost[i]:0;
            dp[i] = Math.Min(dp[i-1], dp[i-2]) + addend;
            
        }
        
        return dp[dp.Length-1];
    }
}


/*
dp[0] = 10
dp[1] = 15

dp[2] = min(dp[2-1], dp[2-2])+cost[2]
dp[3] = min(dp[3-1], dp[3-2])+cost[3]
*/