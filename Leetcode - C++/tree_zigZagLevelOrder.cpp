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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res; 
        if(!root) return res;
        bool isLeftToRight = true;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
        	int n = q.size();
        	vector<int> level(n);
        	int i = 0;
        	while(i < n){
        		TreeNode* temp = q.front();
        		q.pop();
        		int index = (isLeftToRight) ? i : n-i-1;
        		level[index] = temp->val;
        		if(temp->left != NULL) q.push(temp->left);
        		if(temp->right != NULL) q.push(temp->right);
        		i++;
        	}
        	isLeftToRight = !isLeftToRight;
        	res.push_back(level);
        }
        return res;
    }
};