#include <iostream>
#include <queue>

using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode* l, TreeNode* r) {
    if(!l && !r) return true;
    if(!l || !r) return false;
    return (l->val == r->val) && helper(l->left, r->right) && helper(l->right, r->left);
}

bool isSymmetric(TreeNode* root) {
    return helper(root, root);
}

bool isSymmetricIter(TreeNode* root) {
    // return helper(root, root);
    queue<TreeNode *> q;
    q.push(root);
    q.push(root);
    while(!q.empty()){
        TreeNode* q1 = q.front();
        q.pop();
        TreeNode* q2 = q.front();
        q.pop();
        if(q1 == NULL && q2 == NULL) continue; 
        if(q1 == NULL || q2 == NULL) return false;
        if(q1->val != q2->val) return false;
        q.push(q1->left);
        q.push(q2->right);
        q.push(q1->right);
        q.push(q2->left);
    }
    return true;
}

int main() {

}

//O(n) time and space complexity