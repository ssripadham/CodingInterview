#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

 struct TreeNode {
    int val;    
   TreeNode *left;
   TreeNode *right;
   
   TreeNode(int data){
       val = data;
       left = NULL;
       right = NULL;
   }
 };
 
/*
 *
 *    2
 *  /   \
 * 1     3
 * [2, 1, 3]
 *  2
 *   \
*       3
 *       \
  *        1
  * [2, null, 3, null, 1]
 */

void printTree(struct TreeNode* root){
    
    queue<TreeNode*> q;
    q.push(root);
    
    struct TreeNode* curr;
    while (!q.empty()){

        curr = q.front(); q.pop();
     
        if (curr == NULL){
            cout<<"null, ";
            continue;
        }    
        
        cout<<curr->val<<", ";

        if (curr->left == NULL && curr->right == NULL)
            continue;
            
        q.push(curr->left);
        
        q.push(curr->right);
    
    }
    
}


/*

TreeNode *[] generateTrees(int n) 
Input: 3 -> Seq: 1, 2, 3
Outoput:
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

vector<TreeNode*> generateTreeUtil(int rootVal, int leftIndex, int rightIndex) {
    
    if (leftIndex > rightIndex) {
    
        TreeNode* root = new TreeNode(rootVal);
        vector<TreeNode*> output;
        
        for (int rootVal = leftIndex; rootVal <= rightIndex; rootVal++){
    
        
            vactor<TreeNode*> leftTrees  = generateTreeUtil(rootVal, leftIndex, rootVal -1, output);
            vector<TreeNode*> rightTrees = generateTreeUtil(rootVal, rootVal+1, rightIndex, output);
        
            /*
            */         
        
        }
    }
    
    return output;
    
}
    
    
    
}

vector<TreeNode*> generateTrees(int n){
    
    vector<TreeNode*> output;
    output = generateTreeUtil(?, 1, n);
    
    
}


int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    root->right->right = new TreeNode(4);
    
    printTree(root);
    
    
    return 0;
}

