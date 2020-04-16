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
	void inOrder(TreeNode* node, vector<int>& res) {
		if(!node)
			return;
		inOrder(node->left, res);
		res.push_back(node->val);
		inOrder(node->right, res);
	}

public:
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> res;
       inOrder(root, res); 
       return res; 
    }
};