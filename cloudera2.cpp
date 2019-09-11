
/**
 * Given an unsorted tree of unique elements, find the common 
 * ancestor of two nodes. For example, given this tree:
 *
 *              5
 *             / \
 *            6   3
 *           / \
 *          9   1
 *               \
 *                8
 * 
 * commonAncestor(9,1) == 6
 * commonAncestor(1,3) == 5
 * commonAncestor(6,1) == 5
 * commonAncestor(9,8) == 6
 */

class Tree {
    struct Node {
        // should be unique in the tree
        int value;

        // child nodes
        Node* left;
        Node* right;
    };

    Node* mRoot;
    
    Node* findUtil(Node* root, Node* a){
    
        if (root == NULL || a == NULL) {
            return NULL;
        }
        
        if (root->data == a->data) {
            return root;
        }
        
        if findUtil(root->left, a) return root->left;
        if findUtil(root->right, a) return root->right;
     
        return NULL;       
    }
        
    
   
    
    struct Node* commonAncestorUtil(struct Node* a, struct Node* b, struct Node* root, struct node* parent) {
    
        if (root == NULL) return NULL;
        
        if (a = NULL || b == NULL) return root;
        
        if ((root->right = a  && root->left = b) || (root->left = a && root->right = b) {
            return root;
        }
        
      
        
        bool aIsLeft = findUtil(root->left,a) != NULL;
        bool aIsRight = findUtil(root->right,a) != NULL;
        
        bool bIsLeft = findUtil(root->left, b) != NULL;
        bool bIsRight = findUtil(root->right,b) != NULL;
        
        
               
        if (aIsLeft && bIsRight || aIsRight && bIsLeft) {
            return root;
       } 
       
       if (aIsLeft && bIsLeft) return commonAncestor(a, b, root->left, root);
       
       if (aIsRight && bIsRight) return commonAncestor(a,b, root->right, root);
       
       return NULL;
            
    }
    
    
}

