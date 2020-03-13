/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/

public class Solution {
    public int NumDecodings(string s) {
        if (string.IsNullOrEmpty(s)) return 0;
        Dictionary<string, int> cache = new Dictionary<string, int>();
        return NumDecodeUtil(s, cache);
    }

    private int NumDecodeUtil(string s, Dictionary<string, int> cache) {
        
        if (s == string.Empty) return 1;
        
        if (cache.ContainsKey(s)) return cache[s];
        
        int count = 0;
        
        int val = Convert.ToInt32(s.Substring(0,1   ));
        
        if (val > 0 && val <= 9){
            count += NumDecodeUtil(s.Substring(1), cache);
        }
        
        if (s.Length > 1) {
            val = Convert.ToInt32(s.Substring(0,2));
            if (val >= 10 && val <= 26){
                count += NumDecodeUtil(s.Substring(2), cache);
            }
        }
        
        cache[s] = count;
        return count;
    }
}