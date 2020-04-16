#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int preIndex = 0, postIndex = 0;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode* root = new TreeNode(pre[preIndex++]);
        if(root->val != post[postIndex])
        	root->left = constructFromPrePost(pre, post);
        if(root->val != post[postIndex])
        	root->right = constructFromPrePost(pre, post);
        postIndex++;
        return root;
    }
};