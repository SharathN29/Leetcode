#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> res; 

void inorder(TreeNode* head) {
	if(head == NULL) return;
	inorder(head->left);
	res.push_back(head->val);
	inorder(head->right);
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
	inorder(root1);
	inorder(root2);
	return sort(res.begin(), res.end());
}