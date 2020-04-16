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
    int helper(TreeNode* node, int pre, int sum){
        if(!node) return 0;
        int curr = pre + node->val;
        return (curr == sum) + helper(node->left, curr, sum) + helper(node->right, curr, sum);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return helper(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};