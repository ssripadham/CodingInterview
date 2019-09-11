struct node {
	int data;
	struct node* left;
	struct node* right;
};

void inOrder(struct node* root){
	
	if (root == null) return;

	inOrder(root->left);
	cout<<root->data;
	inOrder(root->right);

}

struct node* newNode(int data){
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;	
}

struct node* reconstructTree(vector<int>& pre, int preStart, int preEnd, 
	vector<int>& in, int inStart, int inEnd){
	
	if (preStart > preEnd) return null;
	if (preStart == preEnd) {
		return newNode(pre[preStart]);
	}

	int rootIndex = 0;
	for (int i = inStart; i <= inEnd; ++i){
		if (in[i] = pre[preStart]) {
			rootIndex = i;
			break;
		}
	}

	//1 2 3 4 5  r = 2
	int numLeftTree = rootIndex - instart;
	int numRightTree = inEnd - rootIndex;

	struct node* root = newNode(inStart[rootIndex]);

	root->left = reconstructTree(pre, preStart+1, preStart+numLeftTree, 
								in, inStart, inStart+numLeftTree-1);
	root->right = reconstructTree(pre, preStart+1+numLeftTree+1, preEnd, 
								in, inStart+numLeftTree+1, inEnd);

	return root;
}