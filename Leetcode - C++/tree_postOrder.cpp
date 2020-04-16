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
	void postOrder(TreeNode* node, vector<int>& res) {
		if(!node) return;
		postOrder(node->left, res);
		postOrder(node->right, res);
		res.push_back(node->val);
	}
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res; 
        postOrder(root, res);
        return res;
    }
};