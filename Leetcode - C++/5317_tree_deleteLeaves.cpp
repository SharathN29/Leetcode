// https://leetcode.com/contest/weekly-contest-172/problems/delete-leaves-with-a-given-value/

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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return NULL;
        if(root->left) root->left = removeLeafNodes(root->left, target);
        if(root->right) root->right = removeLeafNodes(root->right, target);
        if(root->val == target && !root->left && !root->right) {L
            return NULL;
        }
        return root; 
    }
};