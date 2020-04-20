/*
Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
 

Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

Example 1:

Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
 

Note:

The n will be in the range [1, 1000].
*/
public class Solution {
    public int MinSteps(int n) {
        int[] dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <=n ; ++i){
            dp[i] = i;
            for (int j = i-1; j > 1; --j){
                if (i%j == 0){
                    dp[i] = dp[j]+(i/j);
                    break;
                }
            }
        }
        return dp[n];
    }
}

/*
 AAAA
 
 3  = Min(dp(2),Min(dp(1))) AA+Copy+Paste
 2 = A + Cp + Paste AA
 1 = 0
 
5 = 2*2 + 1
    1*4 + 1
    AAAA
    
    A
    AAA 3
    AAAA  min (dp(2) + 2 or A c p p p  AAAA dp(1)+4)
    AAAAA A Cp P P P P dp(1)+5
    AAAAAA dp(3) + 2, dp(1)+ 6
    AAAAAAA 
    
*/