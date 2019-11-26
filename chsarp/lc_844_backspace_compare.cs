/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c"
*/

public class Solution {
    
    private string processString(string S){    
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < S.Length; ++i){
            if (S[i] == '#'){
                if (sb.Length > 0)
                    sb.Length--;
            } else {
                sb.Append(S[i]);
            }
        }
        return sb.ToString();
    }
    
    
    public bool BackspaceCompare(string S, string T) {
        return (processString(S) == processString(T));
    }
    
}