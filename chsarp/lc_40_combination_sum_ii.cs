/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/
public class Solution {
    
    IList<IList<int>> output = new List<IList<int>>();
    List<int> lst = new List<int>();
    
    private void CombinationSum2Helper(int[] candidates, int curIndex, int sum, int target){
        
        if (target == sum){
            output.Add(new List<int>(lst));
            return;
        }
        if (curIndex == candidates.Length || sum > target) return;
        for (int i = curIndex; i < candidates.Length; ++i){
            
            if (i> curIndex && candidates[i-1]==candidates[i]) continue;
            lst.Add(candidates[i]);
            CombinationSum2Helper(candidates, i+1, sum+candidates[i], target);
            lst.Remove(candidates[i]);
        }
        
        return;
    }
    
    public IList<IList<int>> CombinationSum2(int[] candidates, int target) {
        Array.Sort(candidates);
        CombinationSum2Helper(candidates, 0, 0, target);
        return output.ToList();
    }
}