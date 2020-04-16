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
        int length = 0;
        dfs(root, root, length);
        return length;
    }

private:
    pair<int,int> dfs(TreeNode* node, TreeNode* parent, int length) {
        if(node == NULL) 
            return make_pair(0,0);
        auto left = dfs(node->left, node, length);
        auto right = dfs(node->right, node, length);
        longest = max(longest, left.first + right.second + 1);
        longest = max(longest, left.second + right.first + 1);
        int inc = 0, dec = 0;
        if ( node->val == parent->val + 1 ) {
            inc = max(left.first, right.first) + 1;
        }
        if ( node->val == parent->val - 1 ) {
            dec = max(left.second, right.second) + 1;
        }
        return make_pair(inc,dec);
    }
};