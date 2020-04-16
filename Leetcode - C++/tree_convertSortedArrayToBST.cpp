#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* helper(vector<int>& nums, int left, int right){
		if(left > right) return NULL;
		int p = (left+right)/2;
		TreeNode* root = new TreeNode(nums[p]);
		root->left = helper(nums, left, p-1);
		root->right = helper(nums, p+1, right);
		return root;
	}

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};