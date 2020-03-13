/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
*/
public class Solution {
    public bool WordBreak(string s, IList<string> wordDict) {
        HashSet<string> cache = new HashSet<string>();
        return WordBreakUtil(s, wordDict, cache);
    }


    private bool WordBreakUtil(string s, IList<string> wordDict, 
                          HashSet<string> cache) {
        
        if (wordDict.Contains(s)) return true;
        
        if (cache.Contains(s)) return false;
       
        for (int i = 0; i < s.Length; ++i){
            string strSoFar = s.Substring(0, i);
            string rest = s.Substring(i);
            if(wordDict.Contains(strSoFar)){
                if (WordBreakUtil(rest, wordDict, cache)) return true;
            }
        }
        cache.Add(s);
        return false;
    }
}

/*
// Caching when true:
// This will be slower

public class Solution {
    public bool WordBreak(string s, IList<string> wordDict) {
        HashSet<string> cache = new HashSet<string>();
        return WordBreakUtil(s, wordDict, cache);
    }


    private bool WordBreakUtil(string s, IList<string> wordDict, 
                          HashSet<string> cache) {
        
        if (wordDict.Contains(s)) return true;
        
        if (cache.Contains(s)) return true;
       
        for (int i = 0; i < s.Length; ++i){
            string strSoFar = s.Substring(0, i);
            string rest = s.Substring(i);
            if(wordDict.Contains(strSoFar)){
                if (WordBreakUtil(rest, wordDict, cache)) {
                    cache.Add(rest);
                    return true;
                }
            }
        }
        
        return false;
    }
}

*/