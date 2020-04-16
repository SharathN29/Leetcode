#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) {
		this.val = val;
	}
};

void insert(TreeNode* root, int data) {
	if(root == NULL) 
		root = new TreeNode(data);
	if(root->val <= data) {
		if(root->left == NULL)
			root->left = new TreeNode(data);
		else root->left = insert(root->left, data);
	} else {
		if(root->right == NULL)
			root->right = new TreeNode(data);
		else root->right = insert(root->right, data);
	}
}

bool contains(TreeNode* root, int data) {
	if(root == NULL) return false;
	if(root->val == data) return true; 
	if(root->val > data){
		if(root->left == NULL)
			return false;
		else return contains(root->left, data);
	} else {
		if(root->right == NULL)
			return false;
		else return contains(root->right, data);
	}
}

void printInOrder(TreeNode *root) {
	if(root->left != NULL)
		printInOrder(root->left);
	cout << root->val << " ";
	if(root->right != NULL)
		printInOrder(root->right);
}