/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
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
    public IList<double> AverageOfLevels(TreeNode root) {
        
        Queue<TreeNode> currentLevelQ = new Queue<TreeNode>();
        Queue<TreeNode> nextLevelQ = new Queue<TreeNode>();
        
        IList<double> output = new List<double>();
        
        if (root == null){
            return output;
        }
        
        currentLevelQ.Enqueue(root);
        
        double sum = 0;
        int numElements = 0;
        
        while (currentLevelQ.Count != 0) {
            
            TreeNode currentNode = currentLevelQ.Dequeue();
            
            sum += currentNode.val;
            numElements += 1;
            
            if (currentNode.left != null) nextLevelQ.Enqueue(currentNode.left);
            if (currentNode.right != null) nextLevelQ.Enqueue(currentNode.right);
            
            if (currentLevelQ.Count == 0){
                output.Add(sum/numElements);
                
                Queue<TreeNode> tmp = null;
                tmp = currentLevelQ;
                currentLevelQ = nextLevelQ;
                nextLevelQ = tmp;
                
                nextLevelQ.Clear();
                sum = 0;
                numElements = 0;
            }
            
        }
        
        return output;
        
    }
}