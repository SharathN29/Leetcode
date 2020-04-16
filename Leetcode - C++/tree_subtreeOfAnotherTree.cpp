#include <iostream> 

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSubtree(TreeNode* s, TreeNode* t) {
    return traverse(s,t);
}

bool traverse(TreeNode* s, TreeNode* t) {
	return s != NULL && (equals(s,t) || traverse(s->left, t) || traverse(s->right, t));
}

bool equals(TreeNode* x, TreeNode* y) {
	if(x == NULL && y == NULL) return true; 
	if(x == NULL || y == NULL) return false;
	return x->val == y->val && equals(x->left, y->left) && equals(x->right, y->right);
}
