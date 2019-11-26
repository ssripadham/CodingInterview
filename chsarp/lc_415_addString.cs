/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly. 
 */
public class Solution {
    
    string Reverse(string str){
        char[] charArray = str.ToCharArray();
        Array.Reverse(charArray);
        string revStr = new string(charArray);
        return revStr;
    }
    
    public string AddStrings(string num1, string num2) {
        
        
        string strNum1 = Reverse(num1);
        string strNum2 = Reverse(num2);
        
        int maxLength = Math.Max(strNum1.Length, strNum2.Length);
        
        StringBuilder sb = new StringBuilder();
        
        int carry = 0;
        for (int i = 0; i < maxLength; ++i){
            
            int n1 = (i < strNum1.Length)? strNum1[i] - '0' : 0;
            int n2 = (i < strNum2.Length)? strNum2[i] - '0' : 0;
            
            int sum = (n1+n2+carry)%10;
            
            sb.Append(sum.ToString());
            carry = (n1+n2+carry)/10;
        }
        
        if (carry > 0){
            sb.Append(carry.ToString());
        }
        
        return Reverse(sb.ToString());
    }
}
