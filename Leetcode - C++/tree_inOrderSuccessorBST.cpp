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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p->right){
        	p = p->right;
        	while(p->left)
        		p = p->left;
        }
        TreeNode* candidate = NULL;
        while(root != p)
        	root = (p->val > root->val) ? root->right : (candidate = root)->left;
        return candidate;
    }
};