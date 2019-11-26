/*
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].
*/

public class Solution {
    
    private string Reverse(string s){
        
        char [] charArr = s.ToCharArray();
        Array.Reverse(charArr);
        return new string(charArr);
        
    }
    
    public string ConvertToBase7(int num) {
     
        int q = Math.Abs(num);
        
        int r  = 0;
        StringBuilder sb = new StringBuilder();
        while(q>=7){
            
            r = q%7;
            sb.Append(r.ToString());
            q /= 7;
        }
        sb.Append(q);
        if (num < 0) sb.Append('-');
        return Reverse(sb.ToString());   
    }
}