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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
        	vector<int> level; 
            int len = q.size();
        	for(int i = 0; i < len; i++) {
        		TreeNode* temp = q.front();
        		q.pop();
        		level.push_back(temp->val);
        		if(temp->left != NULL) q.push(temp->left);
        		if(temp->right != NULL) q.push(temp->right);
        	}
        	res.push_back(level);
        }
        return res;
    }
};