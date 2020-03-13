/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/


public class Solution {
    public string Convert(string s, int numRows) {
        
        int counter = 0; int dir = 1;
        List<StringBuilder> rows = new List<StringBuilder>();
        for (int i = 0; i< numRows; ++i){
            rows.Add(new StringBuilder());
        }
        
        for (int i = 0; i < s.Length; ++i){
           
            if (counter == 0) { dir = 1;}
            if (counter == numRows-1) { dir = -1;}
            
            rows[counter].Append(s[i]);
                
            if (dir == 1) { counter++; } else { counter--;}
            if (counter < 0 ) counter = 0;
            
        }
        
        StringBuilder output = new StringBuilder();
        for (int i = 0; i < numRows; ++i){
            output.Append(rows[i].ToString());
        }
        
        return output.ToString();
    }
}