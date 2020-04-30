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
        int maxSum = Int32.MinValue;
        MaxPathSumUtil(root, ref maxSum);
        return maxSum;
    }
    
private int MaxPathSumUtil(TreeNode root, ref int  maxSum) {
        
         
        if (root == null) {
            return 0;
        }
        
        int pathSumLeft  = MaxPathSumUtil(root.left, ref maxSum);
        int pathSumRight = MaxPathSumUtil(root.right, ref maxSum);
    
        int leftOrRightOrNode = Math.Max(root.val, root.val + Math.Max(pathSumLeft, pathSumRight));
        maxSum = Math.Max( maxSum, Math.Max(root.val+pathSumLeft+pathSumRight,leftOrRightOrNode));
        return leftOrRightOrNode;
        
    }
}
