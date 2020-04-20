/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].
*/
public class Solution {
    public bool CheckValidString(string s) {
        if (String.IsNullOrEmpty(s)){
            return true;
        }
        HashSet<Tuple<int,int,int>> cache = new HashSet<Tuple<int,int,int>>();
        return CheckValidStringUtil(s, 0, 0, 0, cache);
    }
    
    private bool CheckValidStringUtil(string s, int index, int numLeft, int numRight, HashSet<Tuple<int,int,int>> cache){
        if (numRight > numLeft){
            return false;
        }
            
        if (index == s.Length){
            return numLeft == numRight;
        }
        
        //check cache
        if (cache.Contains(new Tuple<int,int,int>(index, numLeft, numRight))){
            return false;
        }
        
        bool retVal = true;
        if (s[index] == '('){
            retVal = CheckValidStringUtil(s, index+1, numLeft+1, numRight, cache);
        }
        
        if (s[index] == ')'){
            retVal = CheckValidStringUtil(s, index+1, numLeft, numRight+1, cache);
        }
        
        if (s[index] == '*'){
             retVal = CheckValidStringUtil(s, index+1, numLeft+1, numRight, cache) ||
                CheckValidStringUtil(s, index+1, numLeft, numRight+1, cache) ||
                CheckValidStringUtil(s, index+1, numLeft, numRight, cache);
        }
        
        if (!retVal){
            cache.Add(new Tuple<int,int,int>(index,numLeft,numRight));
            return false;
        }
        
        return retVal;

    }
}