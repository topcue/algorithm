#include <iostream>

struct node {
	char data;
	struct node* left;
	struct node* right;
};

void inOrder(node* root) {
	if(root == NULL) {
		return;
	}
	inOrder(root->left);
	printf("%c ", root->data);
	inOrder(root->right);
}

void preOrder(node* root) {
	if(root == NULL) {
		return;
	}
	printf("%c ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(node* root) {
	if(root == NULL) {
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf("%c ", root->data);
}

int size(struct node* root) {
	if(root == NULL) {
		return 0;
	} else {
		return (size(root->left) + size(root->right) + 1);
	}
}

int height(struct node* root) {
	int lDepth, rDepth;
	if (root == NULL) {
		return 0;
	}
	lDepth = height(root->left);
	rDepth = height(root->right);
	
	return (lDepth > rDepth)?(lDepth+1):(rDepth+1);
}

void mirror(struct node* root) {
	if (root == NULL) {
		return;
	}
	mirror(root->left);
	mirror(root->right);

	struct node* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}

int sumOfWeight(struct node* root) {
	if(root == NULL){
		return 0;
	} else {
		return (sumOfWeight(root->left) + sumOfWeight(root->right) + root->data);
	}
}

int maxPathWeight(struct node *root) {
	int leftWeight, rightWeight;
	if(root == NULL) {
		return 0;	
	}
	leftWeight = maxPathWeight(root->left);
	rightWeight = maxPathWeight(root->right);
	return (root->data + leftWeight) >= rightWeight ? leftWeight : rightWeight;
}

int main() {


	return 0;	
}

// EOF
