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
    int longestConsecutive(TreeNode* root) {
        dfs(root, NULL, 0);
    }

private: 
    int dfs(TreeNode* p, TreeNode* parent, int length) {
        if(p == NULL) return length; 
        length = (parent != NULL && p->val == parent->val + 1) ? length + 1 : 1; 
        return max(length, max(dfs(p->left, p, length), dfs(p->right, p, length)));
    }
};