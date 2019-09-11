#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
	struct node* left;
	struct node* right;
	int data;
};

struct node* insert(struct node* root, int data) {
	
	if (root == NULL) {
		struct node* newNode = (struct node*) malloc(sizeof(struct node));
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	if (data < root->data) {
		root->left = insert(root->left,data);
	} else {
		root->right = insert(root->right,data);
	}

	return root;
}

void inOrder(struct node* root){
	if (root == NULL) return;
	inOrder(root->left);
	cout<<root->data<<endl;
	inOrder(root->right);
}


void printList(struct node* head){

	cout<<"List:"<<endl;
	struct node* current = head;

	while (current != NULL) {
		cout<<current->data<<endl;
		current = current->right;
		if (current == head) break;
	}
}

//Join two nodes
void join(struct node* a, struct node* b){
	a->right = b;
	b->left = a;
}


//Join two circular Lists and return list
struct node* append(struct node* a, struct node* b){

	if (a == NULL) return b;
	if (b == NULL) return a;

	struct node* aLast = a->left;
	struct node* bLast = b->left;

	join(aLast,b);
	join(bLast,a);

	return a;
}

struct node* treeToList(struct node* root){
	
	if (root == NULL) return NULL;

	struct node* leftList  = treeToList(root->left);
	struct node* rightList = treeToList(root->right);

	//Leap of faith

	//Make root as a single node circular list
	root->right = root;
	root->left  = root;

	//Join leftList and root
	leftList = append(leftList,root);
	leftList = append(leftList,rightList);

	return leftList;
}


int main(){

	struct node* root = NULL;
	root = insert(root,4);
	root = insert(root,2);
	root = insert(root,3);
	root = insert(root,5);
	root = insert(root,1);
	inOrder(root);

	struct node* list = treeToList(root);
	printList(list);
}

