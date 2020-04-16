// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Time : O(log n), Space : O(1)

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         while(root) {
//         	if(root->left && root->right){
//         		TreeNode* t = root->left; 
//         		while(t->right)
//         			t = t->right;
//         		t->right = root->right;
//         	}
//         	if(root->left)
//         		root->right = root->left;
//         	root->left = NULL;
//         	root= root->right;
//         }
//     }
// };


class Solution {
public:
	void flatten(TreeNode* root) {
		if(root == NULL) return;
		stack<TreeNode *> s; 
		s.push(root);
		while(!s.empty()) {
			TreeNode* temp = s.top();
			s.pop();
			if(temp->right != NULL) s.push(temp->right);
			if(temp->left != NULL) s.push(temp->left);

			if(!s.empty()) temp.right = s.top();
			temp.left = NULL;
		}
	}
};