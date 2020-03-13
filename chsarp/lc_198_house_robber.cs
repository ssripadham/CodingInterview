/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/
public class Solution {
    public int Rob(int[] nums) {
        Dictionary<int, int> cache = new Dictionary<int, int>();
        return RobUtils(nums,0, cache);
    }
    
    private int RobUtils(int[] nums, int i, Dictionary<int, int> cache){
        if (i >= nums.Length) return 0;
        if (cache.ContainsKey(i)) return cache[i];
        int val1 = nums[i]+RobUtils(nums,i+2, cache);
        int val2 = RobUtils(nums, i+1, cache);
        
        cache[i] = Math.Max(val1, val2);
        return cache[i];
    }
} 