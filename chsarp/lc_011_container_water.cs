/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.


Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/
public class Solution {
    public int MaxArea(int[] height) {
        
        int l = 0;
        int r = height.Length - 1;
        int width = height.Length - 1;
        int maxArea = 0;
        while (r > l){
            maxArea = Math.Max(maxArea, Math.Min(height[l], height[r])* width);
            
            if (height[l]<=height[r]) 
                l++; 
            else 
                r--;
            width--;
            
        }
        
        return maxArea;
        
    }
}