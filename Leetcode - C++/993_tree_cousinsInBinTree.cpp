// https://leetcode.com/problems/cousins-in-binary-tree/

#include <iostream>
#include <map>

using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    map<int, int> depth;
    map<int, TreeNode *> parent;
    
    void dfs(TreeNode* node, TreeNode* par) {
        if(node != nullptr) {
            depth[node->val] = par != nullptr ? 1 + depth[par->val] : 0;
            parent[node->val] = par; 
            dfs(node->left, node);
            dfs(node->right, node);
        }
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, nullptr);
        return (depth[x] == depth[y] && parent[x] != parent[y]);
    }
};