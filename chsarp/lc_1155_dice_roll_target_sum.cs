/*
You have d dice, and each die has f faces numbered 1, 2, ..., f.

Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice so the sum of the face up numbers equals target.

Example 1:

Input: d = 1, f = 6, target = 3
Output: 1
Explanation: 
You throw one die with 6 faces.  There is only one way to get a sum of 3.
Example 2:

Input: d = 2, f = 6, target = 7
Output: 6
Explanation: 
You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: d = 2, f = 5, target = 10
Output: 1
Explanation: 
You throw two dice, each with 5 faces.  There is only one way to get a sum of 10: 5+5.
Example 4:

Input: d = 1, f = 2, target = 3
Output: 0
Explanation: 
You throw one die with 2 faces.  There is no way to get a sum of 3.
Example 5:

Input: d = 30, f = 30, target = 500
Output: 222616187
Explanation: 
The answer must be returned modulo 10^9 + 7.
 

Constraints:

1 <= d, f <= 30
1 <= target <= 1000
*/
public class Solution {
    public int NumRollsToTarget(int d, int f, int target) {

        // Map: i -> sum -> value
        Dictionary<int, Dictionary<int, int>> cache =
            new Dictionary<int,Dictionary<int,int>>();
        return NumRollToTargetUtils(d, f, target, 0, 0, cache);        
    }
    
    private int NumRollToTargetUtils(int d, int f, int target, 
                                     int sumSoFar, int numTurnsSoFar, Dictionary<int, Dictionary<int, int>> cache){

        if (sumSoFar > target) return 0;
    
        if (numTurnsSoFar == d) {
            return (sumSoFar == target)? 1 : 0;
        }
        
        if (!cache.ContainsKey(numTurnsSoFar)) {
            cache[numTurnsSoFar] = new Dictionary<int, int>();
        }

        if (cache[numTurnsSoFar].ContainsKey(sumSoFar)) {
            int cached = cache[numTurnsSoFar][sumSoFar];
            return cached;
        }
        
        int numWins = 0;
        for (int i = 1; i <= f; ++i){
            numWins += NumRollToTargetUtils(d, f, target, sumSoFar + i, numTurnsSoFar+1, cache) ; 
            numWins = numWins % 1_000_000_007;
        }
    
        cache[numTurnsSoFar].Add(sumSoFar,numWins);
        return numWins;
    }
    
}