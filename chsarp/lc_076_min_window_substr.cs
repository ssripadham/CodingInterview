/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/
public class Solution {
    
    private void initMap(Dictionary<char, int> myMap, string t){
    
        for (int i = 0; i < t.Length; ++i){
            if (myMap.ContainsKey(t[i])){
                myMap[t[i]]--;
            } else {
                myMap[t[i]] = -1;
            }
        }
    }
    
    private bool isAllPresent(Dictionary<char, int> myMap){
    
        foreach(var kv in myMap) {
            if (kv.Value < 0) return false;
        }
        
        return true;
    }
    
    public string MinWindow(string s, string t) {
        
        Dictionary<char, int> myMap = new Dictionary<char, int>();
        initMap(myMap,t);
        
        int l = 0;
        int r = 0;
        
        string output = new string("");
        while (l < s.Length){
            
            if (myMap.ContainsKey(s[l])) {
                myMap[s[l]]++;
                break;
            }       
            l++;
        }
        
        if (myMap.Count == 0) {
            return output;
        }
        
        r = l+1;
        int minLen = int.MaxValue;
        int lastR = 0;
        while (r < s.Length ){
            
            if (myMap.ContainsKey(s[r])) {
                myMap[s[r]]++;
                if (isAllPresent(myMap)) {
                    if (r - l + 1 < minLen) {
                        output = s.Substring(l, r-l+1);
                        minLen = r-l+1;
                    }
                    myMap[s[l]]--;
                    l++;
                    while (!myMap.ContainsKey(s[l])) l++;
                }
                lastR = r;
            }
           
            r++;
            
        }

        r--;
        while (l < s.Length){
            if (myMap.ContainsKey(s[l])) {
                Console.WriteLine(s[l]);
                if (isAllPresent(myMap)) {
                    if (r - l + 1 < minLen) {
                        output = s.Substring(l, lastR-l+1);
                        minLen = lastR-l+1;
                    }
                    myMap[s[l]]--;
                    //foreach(var kv in myMap) {
                    //    Console.WriteLine($"  {kv.Key} {kv.Value}" );
                    //}
                }
                
            }
            l++;
        }
        
        return output;
    }
}

/*
Q A D O B E C O D E B A N C
                 *  
                        *

A  -1
B  0
C  0
    
    L = 5  ADOBEC
    L = 6  CODEBAC
    L = 4  BANC
*/
