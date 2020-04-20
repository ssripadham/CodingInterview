/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Note:

The input string length won't exceed 1000.
*/
public class Solution {
    
    public int CountSubstrings(string s) {
        
        int n = s.Length;
        
        int[,] dp = new int[n,n];
        
        int count = 0;
        for (int i = 0; i < n ; ++i){
            dp[i,i] = 1;
            count += 1;
        }

        
        int max = 1;
        for (int l = 2; l <= n ; ++l){
            for (int i = 0 ; i <= n - l ; ++i){
                int j = l + i -1;
                if (s[i] == s[j]){
                    if (dp[i+1, j-1] == j-i-1){
                        dp[i,j] = dp[i+1, j-1] + 2;
                        count += 1;
                    }
                } else {
                    dp[i,j] = 0;
                }
                max = Math.Max(max, dp[i,j]);
            }
        }
    
        
        return count;
    
    }
        
    public int CountSubstringsNoDP(string s) {
        return CountSubstringUtil(s, new Dictionary<string, int>());
    }
    
    private int CountSubstringUtil(string s, Dictionary<string, int> dict) {
        if (string.IsNullOrEmpty(s)){
            return 0;
        }
        
        Console.WriteLine($"{s}");
        if (dict.ContainsKey(s)) return dict[s];
        
        int count = 0;
        for (int i = 1; i <= s.Length; ++i){
            string strSoFar = s.Substring(0,i);
            string remaining = s.Substring(i);
            Console.WriteLine($"{strSoFar} r:{remaining}");
            if (isPalindrome(strSoFar)) count += 1;
            count += CountSubstringUtil(remaining, dict);
        }
        
        dict[s] = count;
        return count;
    }
    
    private bool isPalindrome(string s){
        
        for (int i = 0, j = s.Length - 1; i<=j; ++i, --j){
            if (s[i] != s[j]){
                return false;
            }
        }
        Console.WriteLine($"{s} is a Palindrome");
        return true;
    }
}