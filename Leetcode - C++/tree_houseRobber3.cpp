#include <iostream>
#include <vector>
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
	int rob(TreeNode* root) {
        int take, ignore;
        rob(root, take, ignore);
        return max(take, ignore);
    }
    
    void rob(TreeNode* root, int& take, int& ignore) {
        if (root == NULL) {
            take = 0;
            ignore = 0;
        } else {
            int rTake, rIgnore, lTake, lIgnore;
            rob(root->right, rTake, rIgnore);
            rob(root->left, lTake, lIgnore);
            take = root->val + rIgnore + lIgnore;
            ignore = max(rTake, rIgnore) + max(lTake, lIgnore);
        }
    }
};