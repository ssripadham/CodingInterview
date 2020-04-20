/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
    
        int[] output = new int[nums.Length];
        
        for (int i = 0; i < nums.Length; ++i){
            output[i] = 1;
        }
        /*
        
           1    1    1    1
    ->     1    1    2   2*3  
                                
         1      1    1    1
       2*3*4    4*3  4    1  <-
            
        */
        for (int i = 1 ; i < nums.Length; ++i){
            int prev = nums[i-1];
            output[i] = output[i-1]*prev;
        }
        
        int[] output1 = new int[nums.Length];
        
        for (int i = 0; i < nums.Length; ++i){
            output1[i] = 1;
        }
        
        for (int i = nums.Length-2; i >=0 ; i--){
            int prev = nums[i+1];
            output1[i] = output1[i+1]*prev; 
        }
        
        for (int i = 0 ; i < nums.Length; ++i){
            output[i] = output[i]*output1[i];
        }
        
        return output;
    }

    /* O(1) Space
    public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
    
        int[] output = new int[nums.Length];
        
        for (int i = 0; i < nums.Length; ++i){
            output[i] = 1;
        }
        
        for (int i = 1 ; i < nums.Length; ++i){
            int prev = nums[i-1];
            output[i] = output[i-1]*prev;
        }
        
        int pdt = 1;
        
        for (int i = nums.Length-2; i >=0 ; i--){
            pdt = pdt*nums[i+1]; 
             output[i] = output[i]*pdt;
        }
        return output;
    }
    */
}

}

/*
1 1 1 1
  1 1 1
2   2 2
3 3   3
4 4 4
    

[1,2,3,4]

          1       1*2      1*2*3   
2*3*4    3*4      4

24,12,8,6

     2 * 3 * 4
 1 *     3 * 4
 1 * 2     * 4
 1 * 2 * 3

 1 2 2*3 6*4
 
*/