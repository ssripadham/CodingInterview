#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct node {
	struct node* left;
	struct node* right;
	int data;
};

struct node* insert(int data){
	
	struct node* root = (struct node*) malloc(sizeof(struct node));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;

}

void inOrder(struct node* root) {
	if (root == NULL) return;

	inOrder(root->left);
	cout<<root->data<<endl;
	inOrder(root->right);
}

struct node* convertToBinaryTree(const vector<int> & v, int low, int high){
	
	if (low > high) return NULL;

	//create a node for mid element
	int mid = (low+high)/2;

	//Deal with root.
	//create a node with mid
	struct node* root = insert(v[mid]);

	//Trust the recursion
	root->left = convertToBinaryTree(v, low, mid-1);
	root->right = convertToBinaryTree(v, mid+1, high);

	return root;

}

int main() {
	
	vector<int> v = { 10, 20, 30, 40, 50};
	struct node* root = convertToBinaryTree(v,0,v.size()-1);
	inOrder(root);

}