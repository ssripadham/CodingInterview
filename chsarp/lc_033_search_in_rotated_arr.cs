/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

public class Solution {
    public int Search(int[] nums, int target) {
        return binary_search(nums, 0, nums.Length - 1, target);
    }
    
    private int binary_search(int[] nums, int low, int high, int target){
        
        if (low > high) return -1;
        
        int mid = low + (high - low)/2;
        
        if (nums[mid] == target) return mid;
        
        if (nums[low] <= nums[mid]){
            
            if (nums[low] <= target && target < nums[mid]){
                return binary_search(nums, low, mid-1, target);
            } else {
                return binary_search(nums, mid+1, high, target);
            }
            
        } else {
            
            if (nums[mid] < target && target <= nums[high]){
                return binary_search(nums, mid+1, high, target);
            } else {
                return binary_search(nums, low, mid-1, target);
            }
        }
        
        return -1;
    }
}