#include <iostream>
#include <queue>
#include <set>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	vector<int> ans; 
	map<TreeNode *, TreeNode *> parent;
	set<TreeNode *> visit;

	void findParent(TreeNode* node) {
		if(!node) return;
		if(node->left) {
			map[node->left] = node; 
			findParent(node->left);
		}
		if(node->right) {
			map[node->right] = node;
			findParent(node->right);
		}
	}

	void dfs(TreeNode* node, int K) {
		if(visit.find(node) != visit.end()) return;
		visit.insert(node);
		if(K == 0) {
			ans.push_back(node->val);
			return; 
		}

		if(node->left) {
			dfs(node->left, K-1);
		}
		if(node->right) {
			dfs(node->right, K-1);
		}

		TreeNode* p = parent[node];
		if(p) {
			dfs(p,K-1);
		}
	}

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    	if(!root) return {};
    	findParent(root);
    	dfs(target, k);
    	return ans;
    }
};