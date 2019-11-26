/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
 */
public class Solution {
    public int Calculate(string s) {
                
        Stack<int> st = new Stack<int>();
        
        int num = 0;
        int sign = '+';
        for (int i = 0; i < s.Length; ++i){
            //Console.WriteLine(s[i]);
            
            if (Char.IsDigit(s[i])){
                num = num*10+(s[i]-'0');
            }
            
             if( (! Char.IsDigit(s[i]) &&  s[i] != ' ') || i == s.Length-1){
                
                //Gotten a number
                if (sign == '*'){
                    int lastElem = st.Peek(); st.Pop();
                    st.Push(lastElem*num);
                } else if (sign == '/'){
                    int lastElem = st.Peek(); st.Pop();
                    st.Push(lastElem/num);
                } else {
                    if (sign == '-') num *= -1;
                    st.Push(num);
                }
                
                num = 0;
                sign = s[i];
            }   
        }
    
    
        int x = 0;
        while (st.Count != 0){
                int num1 = st.Peek(); st.Pop();
                x += num1;
        }
        
        return x;
    }
}