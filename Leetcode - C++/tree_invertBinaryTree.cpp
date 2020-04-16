#include <iostream>
#include <queue> 

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* right = invertTree(root->right);
        TreeNode* left = invertTree(root->left);
        root->left = right;
        root->right = left;
        return root;
    }

    TreeNode* invertIter(TreeNode* root) {
        if(!root) return NULL;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            TreeNode* temp = curr->left;
            curr->left = curr->right; 
            curr->right = temp;
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right); 
        }
        return root;
    }
};