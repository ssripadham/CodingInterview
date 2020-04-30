/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public int MaxPathSum(TreeNode root) {
        
        if (root == null) {
            return 0;
        }
        
        if (root.left == null && root.right == null){
            return root.val;
        }
        
        int pathSumLeft = MaxPathSum(root.left);
        int pathSumRight = MaxPathSum(root.right);
        if (root.left == null){
            return Math.Max(Math.Max(root.val, pathSumRight), root.val+pathSumRight);
        }
        
        if (root.right == null){  
            return Math.Max(Math.Max(root.val, pathSumLeft), root.val+pathSumLeft);
        }
        
        int max = Math.Max(root.val+pathSumLeft+pathSumRight, Math.Max(pathSumLeft, pathSumRight));
        return Math.Max(root.val, max);
        
    }
}
