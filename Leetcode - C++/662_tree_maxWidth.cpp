// https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxWidth = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});

        while(!q.empty()) {
            int l = q.front().second, r = l;
            for(int i = 0, n = q.size(); i < n; i++) {
                TreeNode* node = q.front().first; 
                r = q.front().second;
                q.pop();
                if(node->left) 
                    q.push({node->left, r*2});
                if(node->right)
                    q.push({node->right, (r*2)+1});
            }
            maxWidth = max(maxWidth, r+1-l);
        }
        return maxWidth;
    }
};