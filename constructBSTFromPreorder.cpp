/* A O(n^2) program for construction of BST from preorder traversal */
#include <stdio.h> 
#include <stdlib.h> 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct node 
{ 
	int data; 
	struct node *left; 
	struct node *right; 
}; 

// A utility function to create a node 
struct node* newNode (int data) 
{ 
	struct node* temp = (struct node *) malloc( sizeof(struct node) ); 

	temp->data = data; 
	temp->left = temp->right = NULL; 

	return temp; 
} 

// A recursive function to construct Full from pre[]. preIndex is used 
// to keep track of index in pre[]. 
struct node* constructTreeUtil (int pre[], int low, int high) 
{ 
	// Base case 
	if (low > high) 
		return NULL; 

	// The first node in preorder traversal is root. So take the node at 
	// preIndex from pre[] and make it root, and increment preIndex 
	struct node* root = newNode ( pre[low] ); 

	// If the current subarry has only one element, no need to recur 
	if (low == high) 
		return root; 

	// Search for the first element greater than root 
	int cutOff; 
	for ( cutOff = low; cutOff <= high; ++cutOff ) 
		if ( pre[ cutOff ] > root->data ) 
			break; 

	// Use the index of element found in preorder to divide preorder array in 
	// two parts. Left subtree and right subtree 
	root->left = constructTreeUtil ( pre, low+1,  cutOff - 1 ); 
	root->right = constructTreeUtil ( pre, cutOff, high ); 

	return root; 
} 

// The main function to construct BST from given preorder traversal. 
// This function mainly uses constructTreeUtil() 
struct node *constructTree (int pre[], int size) 
{ 
	int preIndex = 0; 
	return constructTreeUtil (pre, 0, size - 1); 
} 

// A utility function to print inorder traversal of a Binary Tree 
void printInorder (struct node* node) 
{ 
	if (node == NULL) 
		return; 
	printInorder(node->left); 
	printf("%d ", node->data); 
	printInorder(node->right); 
} 

// Driver program to test above functions 
int main () 
{ 
	int pre[] = {10, 5, 1, 7, 40, 50}; 
	int size = sizeof( pre ) / sizeof( pre[0] ); 

	struct node *root = constructTree(pre, size); 

	printf("Inorder traversal of the constructed tree: \n"); 
	printInorder(root); 

	return 0; 
} 
