/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
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
    
    int height(TreeNode root){

        if (root == null)
            return 0;
        
        int leftHt = height(root.left);
        int rightHt = height(root.right);
        
        /*note below */
        if (Math.Abs(leftHt - rightHt) > 1) return -1;
        
        return Math.Max(leftHt,rightHt)+1;
        
    }
    
    bool IsBalancedTreeUtil(TreeNode root){
        
        if (root == null)
            return true;
        
        if (height(root) == -1){
            return false;
        }
        
        return IsBalancedTreeUtil(root.left) && IsBalancedTreeUtil(root.right);
    }
    
    public bool IsBalanced(TreeNode root) {
        return IsBalancedTreeUtil(root);
    }
}