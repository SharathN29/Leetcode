// https://leetcode.com/problems/binary-tree-vertical-order-traversal/

#include <iostream>
#include <vector>
#include <map> 
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res; 
        if(!root) return res; 
        map<int, vector<int>> m; 
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0,root));
        while(!q.empty()) {
        	int size = q.size(); 
        	for(int i = 0; i < size; i++) {
        		TreeNode *t = q.front().second;
        		int temp = q.front().first; 
        		q.pop();
        		m[temp].push_back(t->val);
        		if(t->left) q.push(make_pair(temp-1, t->left));
        		if(t->right) q.push(make_pair(temp+1, t->right));
        	}
        }
        for(auto &it : m) res.push_back(it.second);
        return res;
    }
};