/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/
public class Solution {
    public string LongestPalindrome(string s) {
        
        if (String.IsNullOrEmpty(s)) return null;
        
        int[,] dp = new int[s.Length, s.Length];
        
        for (int i = 0; i < s.Length; ++i){
            dp[i,i] = 1;
        }
        
        int n = s.Length;
        int max_val = 1;
        string max_str = s[0].ToString();
        for (int l = 2; l <= n; ++l){
            for (int i = 0 ; i <= n-l; ++i){
                int j = l + i -1;
                
                if (s[i] == s[j]){
                    dp[i,j] = dp[i+1,j-1]+2;
                } else {
                    dp[i,j] = Math.Max(dp[i+1,j], dp[i,j-1]);
                }
                if (max_val < dp[i,j]){
                    max_val = dp[i,j];
                    max_str = s.Substring(i,l);
                }
            }
        }
        return max_str;
    }
}