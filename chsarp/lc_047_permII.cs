/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

public class Solution {
    
    private void PermuteUniqueHelper(int[] nums, IList<IList<int>> result, List<int> lst, bool[] used){
        //lst.ForEach(Console.WriteLine);
        //Console.WriteLine(String.Join(", ", lst));
        if (lst.Count == nums.Length){
            result.Add(new List<int>(lst.ToArray()));
        }
        
        for (int i = 0; i < nums.Length; ++i) {
            if (used[i] || i>0 && nums[i] == nums[i-1] && !used[i - 1]) continue;
            used[i] = true;
            lst.Add(nums[i]);
            PermuteUniqueHelper(nums, result, lst, used);
            used[i] = false;
            lst.RemoveAt(lst.Count-1);
        }
    }
    
    public IList<IList<int>> PermuteUnique(int[] nums) {
    
        IList<IList<int>> result = new List<IList<int>>();
        Array.Sort(nums);
        bool[] used = new bool[nums.Length];
        PermuteUniqueHelper(nums, result, new List<int>(), used);
        return result;
    }
}
