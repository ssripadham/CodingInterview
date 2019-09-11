/*        30
    20      40
  10 25   38
      
          37    
    
       30
     
    22  
  10  25
  
  
  
       30
     /  
    10
       \ 
       25
     22 
     
    if right exists
        bring in left most child of right sub tree 
        and delete left most child of right sub tree
        
     if right does not exist,
        delete the roor node and make left sub tree child of roots parent
            
  */

    
        
  struct node {
     int data;
     struct node * left;
     struct node* right;
     struct node* parent;
  }
  
  bool isLeaf(struct node* root) {
  
    return (root->left == NULL && root->right == NULL);
  }
  
  
  struct node* getLeftMostChild(struct node* root) {
    //if (root == NULL) return NULL;
    struct node* current = root;
    while (current) {
      current = current->left;
    }
    
    return current;
      
  }
  
  void delete(struct node* root, int data) {
  
      if (root == NULL) return;
      
      if (root->data == data) {
          deleteNode(root);
          return;
      } 
      
      if ( data < root->data)  
          return delete(root->left, data);
      else     
          return delete(root->right, data);
 
  }
  
  
  struct node* deleteNode(struct node* root) {
  
      if (root == NULL) return;
  
      if (isLeaf(root)) {
          delete root;
          return;
      }
     
       //bring in left most child of right sub tree 
       // and delete left most child of right sub tree
         
      if (root->right != NULL) {
          struct node* leftMostChild = getLeftMostChild(root->right);
          root->data = leftMostChild->data;
          delete leftMostChild;
          return root;
      } else {
      
           // right does not exist,
           //delete the root node and make left sub tree child of roots parent
          root-> parent = root->left;
          root->left->parent = root->parent;
          delete root;
          return root->left;
      }
               
 }
      
      
      
  
  }     