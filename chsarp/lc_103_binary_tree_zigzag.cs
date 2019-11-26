/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    public IList<IList<int>> ZigzagLevelOrder(TreeNode root) {
        
        IList<IList<int>> outputList = new List<IList<int>>();
        
        if (root == null) return outputList;
        
        Stack<TreeNode> currLevel = new Stack<TreeNode>();
        Stack<TreeNode> nextLevel = new Stack<TreeNode>();
        
        int l2r = 1;
        
        currLevel.Push(root);
        
        int level = 0;
        while (currLevel.Count != 0) {
            
            TreeNode curr = currLevel.Pop();
            if (l2r > 0) {
                if (curr.left != null) { nextLevel.Push(curr.left); }
                if (curr.right != null) { nextLevel.Push(curr.right);}
            } else {
                if (curr.right != null) { nextLevel.Push(curr.right);}
                if (curr.left != null) { nextLevel.Push(curr.left);}
            }
            
            if (outputList.Count <= level){
                outputList.Add(new List<int>());
            }
            
            outputList[level].Add(curr.val);
            
            if (currLevel.Count == 0){
                currLevel = new Stack<TreeNode>(nextLevel.Reverse());
                nextLevel.Clear();
                l2r *= -1;
                level++;
            }
            
        }
        return outputList;
        
    }
}