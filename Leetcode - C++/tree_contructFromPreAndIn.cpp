#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	int preIndex;
	unordered_map<int, int> map;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex = 0;
        int index = 0;
        for(int n : inorder)
        	map[n] = index++;
        return helper(0, inorder.size()-1, preorder, inorder);
    }

    TreeNode* helper(int left, int right, vector<int>& preorder, vector<int>& inorder) {
    	if(left > right) return NULL;

    	int rootVal = preorder[preIndex];
    	TreeNode* root = new TreeNode(rootVal);
    	int index = map[rootVal];
    	preIndex++;

    	root->left = helper(left, index-1, preorder, inorder);
    	root->right = helper(index+1, right, preorder, inorder);
    	return root;
    }
};