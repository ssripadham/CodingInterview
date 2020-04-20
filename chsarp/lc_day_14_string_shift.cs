/*
You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

direction can be 0 (for left shift) or 1 (for right shift). 
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.

 

Example 1:

Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"
Example 2:

Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:  
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
 

Constraints:

1 <= s.length <= 100
s only contains lower case English letters.
1 <= shift.length <= 100
shift[i].length == 2
0 <= shift[i][0] <= 1
0 <= shift[i][1] <= 100
*/
public class Solution {
    public string StringShift(string s, int[][] shift) {
        
        int[] shiftArray = new int[2];
        for (int i = 0; i < shift.Length; ++i){
            shiftArray[shift[i][0]] += shift[i][1];
        }
        
        //Console.WriteLine($"{shiftArray[0] {shiftArray[1]}}");
        
        int diff = shiftArray[0] - shiftArray[1];
        
        if (diff == 0) return s;
        
        diff = diff % (s.Length);
        string s2 = s+s;
        
        if (diff > 0){
            return s2.Substring(diff, s.Length);
        } 

        Console.WriteLine(diff);
        return s2.Substring(s.Length+diff, s.Length);

    }
}
                          
