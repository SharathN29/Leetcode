#include <iostream>
#include <vector>

using namespace std; 

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private: 
	void preOrder(TreeNode* node, vector<int>& res) {
		if(!node) return;
		res.push_back(node->val);
		preOrder(node->left, res);
		preOrder(node->right, res);
	}

public:
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> res;
    	preOrder(root, res);
    	return res; 
    }
};