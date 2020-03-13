/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

public class Solution {
  
    public int LengthOfLongestSubstring(string s) {
        
        if (string.IsNullOrEmpty(s)) return 0;
        
        int i = 0; 
        int j = 0;
        HashSet<char> hs = new HashSet<char>();
        int maxLength = 1; int length = 0;
    
        while (j < s.Length){
            if (hs.Contains(s[j])){
                maxLength = Math.Max(hs.Count, maxLength);
                hs.Remove(s[i]);i++;
            } else {
                hs.Add(s[j]);
                j++;
            }          
        }
        
        maxLength = Math.Max(hs.Count, maxLength);
        return maxLength;
    }
}

