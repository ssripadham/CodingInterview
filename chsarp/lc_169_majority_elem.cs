/*Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/
public class Solution {
    public int MajorityElement(int[] nums) {
        
        if (nums.Length == 0) return Int32.MinValue;
        
        int count = 0;
        
        int maj_elem = nums[0];
        
        for (int i = 0; i < nums.Length; ++i){
            
            if (count == 0){
                maj_elem = nums[i];
            }
            if (nums[i] == maj_elem){
                ++count;
            } else {
                --count;
            }
        }
        
        return maj_elem;
        
    }
}