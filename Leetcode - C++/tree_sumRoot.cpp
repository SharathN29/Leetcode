#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sum;

void dfs(TreeNode* root, int currentSum){
    currentSum = currentSum * 10 + root->val;
    if(!root->left && !root->right)
        sum += currentSum;
    if(root->left)
        dfs(root->left, currentSum);
    if(root->right)
        dfs(root->right, currentSum);
}

int sumNumbers(TreeNode* root) {
    sum = 0;
    if(!root) return sum;
    dfs(root, 0);
    return sum; 
}