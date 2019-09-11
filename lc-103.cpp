/**
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

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        stack<TreeNode*> currentLevel;
        stack<TreeNode*> nextLevel;
        TreeNode* current;
        
        currentLevel.push(root);
        int levelIndex = 0;
        int l2r = 1;
        vector<vector<int>> output;
        if (root) output.push_back(vector<int>());
        while (!currentLevel.empty()){
            
            current = currentLevel.top();
            currentLevel.pop();
            
            if (current == NULL){
                continue;
            }
            
            cout<<levelIndex<<" "<<current->val<<endl;
            output[levelIndex].push_back(current->val);
            
            if (l2r>0){
                if (current->left != NULL) nextLevel.push(current->left);
                if (current->right != NULL) nextLevel.push(current->right);
            } else {
                if (current->right != NULL) nextLevel.push(current->right);
                if (current->left != NULL) nextLevel.push(current->left);
            }
            
            if (currentLevel.empty() && !nextLevel.empty()){
                levelIndex++;
                output.push_back(vector<int>());
                swap(currentLevel, nextLevel);
                l2r *= -1;
            }
        }
        return output;
    }
};