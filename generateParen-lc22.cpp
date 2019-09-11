/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    
    void genParenUtil(string strSoFar, int lR, int rR, vector<string> & output){
        
        if (lR == 0 && rR == 0) {
            output.push_back(strSoFar);
            return;
        }
        
        if (lR > 0) {
            genParenUtil(strSoFar+ "(", lR-1, rR, output);
        }
        
        
        if (lR < rR) {
            genParenUtil(strSoFar+ ")", lR, rR-1, output);
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> output;
        genParenUtil("", n,n, output);
        return output;
    }
};