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
    int deepestLeavesSum(TreeNode* root) {
    	vector<int> res; 
    	queue<TreeNode *> q;
    	q.push(root);
    	while(!q.empty()) {
    		int len = q.size();
    		int tempSum = 0;
    		for(int i = 0; i < len; i++) {
    			TreeNode *temp = q.top();
    			q.pop();
    			tempSum += temp->val; 
    			if(temp>left != NULL) q.push(temp->left);
    			if(temp->right != NULL) q.push(temp->right);
    		}
    		res.push_back(tempSum);
    	}
    	reverse(res.begin(), res.end());
    	return res[0];
    }
};
