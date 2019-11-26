/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
public class Solution {
    
    private void SubsetsHelper(int[] nums, IList<IList<int>> results, 
                               List<int> lst, int start) {
        
        results.Add(new List<int>(lst.ToArray()));
        
        for (int i = start; i < nums.Length; ++i){
            
            if (i > start && nums[i] == nums[i-1]) continue;
            
            lst.Add(nums[i]);
            SubsetsHelper(nums, results, lst, i+1);
            lst.RemoveAt(lst.Count - 1);
        }
        
        return;
    }
    
    public IList<IList<int>> SubsetsWithDup(int[] nums) {
    
        IList<IList<int>> results = new List<IList<int>>();
        Array.Sort(nums);
        SubsetsHelper(nums, results, new List<int>(), 0);
        
        return results;
    }

}