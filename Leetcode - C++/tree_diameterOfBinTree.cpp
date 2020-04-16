// https://leetcode.com/problems/diameter-of-binary-tree/
// Time : O(n), Space : O(n)

#include <iostream>

using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	int ans;
public:
	int depth(TreeNode* node){
		if(node == NULL) return 0;
		int l = depth(node->left);
		int r = depth(node->right);
		ans = max(ans, l+r+1);
		return max(l,r)+1;
	}

    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans-1;
    }
};