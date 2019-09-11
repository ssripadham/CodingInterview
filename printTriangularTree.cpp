/*
Nodes on exterior of binary tree
*/

#include <cstdlib>
#include <iostream>

using namespace std;

struct node {
	struct node* left;
	struct node* right;
	int data;
};

struct node* insert(int data){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
}

bool isLeaf(struct node* root) {
	return (root->left == NULL && root->right == NULL);
}


void inOrder(struct node* root){
	if (root == NULL) return;

	inOrder(root->left);

	if (isLeaf(root))
		cout<<root->data<<" ";

	inOrder(root->right);

}

void preOrder(struct node* root){
	if (root == NULL) return;
	if (!isLeaf(root)) cout<<root->data<<" ";
	preOrder(root->left);
	//preOrder(root->right);
}


void postOrder(struct node* root){
	if (root == NULL) return;
	//postOrder(root->left);
	postOrder(root->right);
	if (!isLeaf(root)) cout<<root->data<<" ";
}


void printTriangle(struct node* root){
	preOrder(root);
	inOrder(root);
	postOrder(root);
}

int main(){

	/*
			  70

		40		   90

	20	  30    80   100

	*/

	struct node* root = insert(70);
	root->left = insert(40);
	root->left->left = insert(20);
	root->left->right = insert(30);
	root->right = insert(90);
	root->right->left = insert(80);
	root->right->right = insert(100);
	printTriangle(root);
}

