/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


         h    o    r    s     e

     0   1    2    3    4     5

r    1   2

o    2

s    3


*/



public class Solution {
    public int MinDistance(string word1, string word2) {

        int[,] dp = new int[word1.Length+1,word2.Length+1];
        
        for (int i = 0; i <= word1.Length; ++i){
    
            for (int j = 0; j <= word2.Length; ++j){
                if (i == 0) {
                    dp[i,j] = j;
                    continue;
                }
                if (j == 0){
                    dp[i,j] = i;
                    continue;
                }
                if (word1[i-1] != word2[j-1]){
                    dp[i,j] = Math.Min(dp[i-1,j-1],Math.Min(dp[i-1,j], dp[i,j-1]))+1; 
                } else {
                    dp[i,j] = dp[i-1,j-1];
                }
            }
        }
        
        return dp[word1.Length,word2.Length];
    
    }
}