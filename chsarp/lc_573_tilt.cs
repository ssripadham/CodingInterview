/*
Given a binary tree, return the tilt of the whole tree.

The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.

The tilt of the whole tree is defined as the sum of all nodes' tilt.

Example:
Input: 
         1
       /   \
      2     3
Output: 1
Explanation: 
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1
Note:

The sum of node values in any subtree won't exceed the range of 32-bit integer.
All the tilt values won't exceed the range of 32-bit integer.
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
    
    private int sum = 0;
    
    private int tiltHelper(TreeNode root){
        if (root == null) return 0;
        
        int leftSum = tiltHelper(root.left);
        int rightSum = tiltHelper(root.right);
        
        sum += Math.Abs(leftSum - rightSum);
        
        return leftSum + rightSum + root.val;
        
        
    }
    public int FindTilt(TreeNode root) {
        
        tiltHelper(root);
        return sum;
        
    }
}