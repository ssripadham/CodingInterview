/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        
        Dictionary<string, List<string>> d = new Dictionary<string, List<string>>();
        
        for (int i = 0; i < strs.Length; ++i){
            
            char[] chArr = strs[i].ToArray();
            Array.Sort(chArr);
            string sortedString = new string(chArr);
            
            if (d.ContainsKey(sortedString)){
                d[sortedString].Add(strs[i]);
            } else {
                d[sortedString] = new List<string>();
                d[sortedString].Add(strs[i]);
            }
        }
        
        IList<IList<string>> output = new List<IList<string>>();
        for (int i = 0; i < d.Count; ++i){
            output.Add(new List<string>(d.ElementAt(i).Value.ToArray()));
        }
        
        return output;
    }
}
