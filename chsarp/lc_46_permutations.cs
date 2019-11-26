/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

public class Solution {
    
     private void PermuteHelper(int[] nums, IList<IList<int>> results, 
                               List<int> lst) {
        
         if (lst.Count == nums.Length){
            results.Add(new List<int>(lst.ToArray()));
         } else {
         
            for (int i = 0; i < nums.Length; ++i){
                if(lst.Contains(nums[i])) continue; 
                lst.Add(nums[i]);
                PermuteHelper(nums, results, lst);
                lst.RemoveAt(lst.Count - 1);
            }
         }
        
        return;
    }
    
    public IList<IList<int>> Permute(int[] nums) {
    
        IList<IList<int>> results = new List<IList<int>>();
        
        PermuteHelper(nums, results, new List<int>());
        
        return results;
    }
  
}