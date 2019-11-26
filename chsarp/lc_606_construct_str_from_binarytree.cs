/**
You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

Output: "1(2(4))(3)"

 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public string Tree2strUtil(TreeNode t) {
        if (t == null) return "";
        StringBuilder sb = new StringBuilder();
        sb.Append(t.val);
        
        if (t.left != null){
            sb.Append("(");
            sb.Append(Tree2strUtil(t.left));
            sb.Append(")");
        }
        if (t.right != null){
            sb.Append("(");
            sb.Append(Tree2strUtil(t.right));
            sb.Append(")");
        }
        return sb.ToString();
    }
    
    public string Tree2str(TreeNode t) {
        return Tree2strUtil(t);
    }
}