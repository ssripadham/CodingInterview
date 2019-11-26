public class Solution {
    
    private bool WordBreakUtil(string s, IList<string> wordDict, int start, HashSet<int> set1){
        if (start == s.Length){
            return true;
        }    
        
        if(set1.Contains(start)) return false;
        
        for (int i = start; i < s.Length; ++i){
            string word = s.Substring(start, i-start+1);
            if (isWord(word, wordDict)){
                if (WordBreakUtil(s, wordDict, i+1, set1)) return true;
            }
        }
        set1.Add(start);
        return false;
    }
    
    private bool isWord(string word, IList<string> wordDict){
        return (wordDict.Contains(word));    
    }
    
    public bool WordBreak(string s, IList<string> wordDict) {
        
        return WordBreakUtil(s, wordDict, 0,new HashSet<int>());    
    }
}