#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode* root, int rootVal) {
    if(!root) return true;
    if(root->val != rootVal) return false;
    return helper(root->left, rootVal) && helper(root->right, rootVal);
}

bool isUnivalTree(TreeNode* root) {
    if(!root) return true;
    int rootVal = root->val;
    return helper(root, rootVal);
}