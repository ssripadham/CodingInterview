/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/

public class Solution {
    
    private string Reverse(string str){
        char[] charArr = str.ToCharArray();
        Array.Reverse(charArr);
        string revStr = new string(charArr);
        return revStr;
    }
    public string AddBinary(string a, string b) {
        
        string a1 = Reverse(a);
        string b1 = Reverse(b);
        
        int maxLen = Math.Max(a1.Length, b1.Length);
        
        StringBuilder sb = new StringBuilder();
        int carry = 0;
        for (int i = 0; i < maxLen; ++i){
            
            int num1 = 0;
            if (i < a1.Length) num1 = a1[i] - '0';
            int num2 = 0;
            if (i < b1.Length) num2 = b1[i] - '0';
            
            int sum = (num1+num2+carry)%2;
            carry = (num1+num2+carry)/2;
            
            sb.Append(sum.ToString());
        }
        if (carry == 1)
            sb.Append(carry.ToString());
       
        return Reverse(sb.ToString());
    }
}