w/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 */
public class Solution {
   
   //Initialization
    IList<IList<int>> output = new List<IList<int>>();
   
    private void CombinationSumHelper(int[] candidates, int currentIndex, int sum, int target, List<int> lst){
       
        if (currentIndex == candidates.Length || sum > target){
            return;
        }
           
        if (sum == target){
            //Deep Copy
            output.Add(new List<int>(lst.ToArray()));
            return;
        }
       
        //Include number in current Index
        lst.Add(candidates[currentIndex]);
        CombinationSumHelper(candidates, currentIndex, sum+candidates[currentIndex], target, lst);
        lst.Remove(candidates[currentIndex]); //No clearing lst in base case
 
    
        //Exclude number in current Index     
        CombinationSumHelper(candidates, currentIndex+1, sum, target, lst);
    }
   
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        List<int> lst = new List<int>();
        CombinationSumHelper(candidates, 0, 0, target, lst);
        return this.output;
    }
}

/* 
Backtrack implentation

public class Solution {
   
    IList<IList<int>> output = new List<IList<int>>();
    List<int> lst = new List<int>();
    
    private void CombinationSumHelper(int[] candidates, int start, int sum, int target){
       
        if (sum > target) return;
           
        if (sum == target){
            output.Add(new List<int>(lst.ToArray()));
            return;
        }
     
        for (int i = start; i < candidates.Length; ++i){
            lst.Add(candidates[i]);
            CombinationSumHelper(candidates, i, sum+candidates[i], target);
            lst.RemoveAt(lst.Count - 1);
        }
    }
   
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        
        CombinationSumHelper(candidates, 0, 0, target);
        return this.output;
    }
}
 */