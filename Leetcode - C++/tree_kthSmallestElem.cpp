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
	void inorder(TreeNode* root, int k, vector<int>& elem) {
		if(!root) return;

		inorder(root->left, k, elem);
		elem.push_back(root->val);
		inorder(root->right, k, elem);
	}

public:
    int kthSmallest(TreeNode* root, int k) {
    	if(!root) return 0;
    	vector<int> elem; 
    	inorder(root, k, elem);
        return elem[k-1];
    }
};