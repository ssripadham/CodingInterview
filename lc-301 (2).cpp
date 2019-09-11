class Solution {
public:
    
    void  removeParenUtil(const string & s,
                          string strSoFar,
                          int index, int numLeftSeen, int numRightSeen,
                          vector<string> & output, set<string> & oset){
        
        if (index == s.length()){
            if (numLeftSeen == numRightSeen &&
              oset.find(strSoFar) == oset.end()) {
                oset.insert(strSoFar);
                output.push_back(strSoFar);
            }
            return;
        }
        
        char ch = s[index];
        
        if (ch != ')') {
           if (ch == '(') {
               removeParenUtil(s, strSoFar+ch, index+1, numLeftSeen+1, numRightSeen, output, oset); 
               removeParenUtil(s, strSoFar, index+1, numLeftSeen+1, numRightSeen, output, oset);
           } else {
                removeParenUtil(s, strSoFar+ch, index+1, numLeftSeen, numRightSeen, output, oset);
           }
        } else {
            //ch == ')', we have two choices
            //1. include
            if (numRightSeen < numLeftSeen){
                removeParenUtil(s, strSoFar+ch, index+1, numLeftSeen, numRightSeen+1, output, oset);
            }
            //2. exclude
            removeParenUtil(s, strSoFar, index+1, numLeftSeen, numRightSeen, output, oset);
        }
        
        return;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> output;    
        set<string> oset;
        removeParenUtil(s, "", 0,  0, 0, output, oset);
        return output;
    }
};