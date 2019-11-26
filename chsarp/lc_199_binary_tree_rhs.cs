/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
  */
  
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public IList<int> RightSideView(TreeNode root) {
        
        Queue<TreeNode> currentLevel = new Queue<TreeNode>();
        Queue<TreeNode> nextLevel = new Queue<TreeNode>();
        
        if (root != null)
            currentLevel.Enqueue(root);
        
        IList<int> output = new List<int>();
        
        while (currentLevel.Count != 0){
            
            if (currentLevel.Count == 1) {
                output.Add(currentLevel.Peek().val);
            }
            
            TreeNode curr = currentLevel.Dequeue();    
            if (curr.left != null){
                nextLevel.Enqueue(curr.left);
            }
            if (curr.right != null){
                nextLevel.Enqueue(curr.right);
            }
            
            if (currentLevel.Count == 0) {
                currentLevel = new Queue<TreeNode>(nextLevel);
                nextLevel.Clear();
            }
        }
            
        return output;
    }
}