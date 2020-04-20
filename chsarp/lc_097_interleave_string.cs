/*
97. Interleaving String
Hard

1165

72

Add to List

Share
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
*/

public class Solution {
    public bool IsInterleave(string s1, string s2, string s3) {
        Dictionary< KeyValuePair<int,int>, bool> cache = new Dictionary< KeyValuePair<int,int>, bool>();
        return InterLeaveUtil(s1, s2, s3, "", 0, 0, cache);
        
    }
    
    private bool InterLeaveUtil(string s1, string s2, string s3, string strSoFar, int index1, int index2, Dictionary< KeyValuePair<int,int>, bool> cache){
        
        //Console.WriteLine("{0} {1}",strSoFar,s3.Substring(0,s1.Length + s2.Length));
        
        if (s3 == strSoFar && s3.Length == s1.Length + s2.Length) return true;
        
        if (s3.Length < s1.Length + s2.Length) return false;
        
        if (cache.ContainsKey(new KeyValuePair<int,int>(index1,index2))) return false;
        if (s3.Substring(0,strSoFar.Length) != strSoFar) return false;
        
        if (index1 < s1.Length){
            if (InterLeaveUtil(s1, s2, s3, strSoFar + s1[index1], index1+1, index2, cache)) return true;
        }
        
        if (index2 < s2.Length){
            if (InterLeaveUtil(s1, s2, s3, strSoFar + s2[index2], index1, index2+1, cache)) return true;
        }
        
        cache[ new KeyValuePair<int,int> (index1,index2)] = false;
        return false;
    }
}