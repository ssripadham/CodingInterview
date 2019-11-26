/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

public class Solution {
    
    private void SubsetsHelper(int[] nums, IList<IList<int>> results, 
                               List<int> lst, int start) {
        
        results.Add(new List<int>(lst.ToArray()));
        
        for (int i = start; i < nums.Length; ++i){
            lst.Add(nums[i]);
            SubsetsHelper(nums, results, lst, i+1);
            lst.RemoveAt(lst.Count - 1);
        }
        
        return;
    }
    
    public IList<IList<int>> Subsets(int[] nums) {
    
        IList<IList<int>> results = new List<IList<int>>();
        
        SubsetsHelper(nums, results, new List<int>(), 0);
        
        return results;
    }
}