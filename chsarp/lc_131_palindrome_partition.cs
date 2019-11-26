/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/


public class Solution {
    
    void backtrack(string s, IList<IList<string>> result, IList<string> tmpList, int start){
        if (start == s.Length){
            result.Add(new List<string>(tmpList.ToArray()));
            return;
        }   
        
        for (int i = start; i < s.Length; ++ i){
            if (isPalindrome(s, start, i)){
                tmpList.Add(s.Substring(start,i-start+1));
                backtrack(s, result, tmpList, i+1);
                tmpList.RemoveAt(tmpList.Count - 1);
            }
        }
        
    }
    
    private bool isPalindrome(string s, int start, int end){
        
        for (int i = start, j = end; i <= j; ++i, --j){
            if (s[i] != s[j]) return false;
        }
        
        return true;
    }
    
    
    public IList<IList<string>> Partition(string s) {
        IList<IList<string>> result = new List<IList<string>>();
    
        backtrack(s, result, new List<string>(), 0);
        return result;
    }
}