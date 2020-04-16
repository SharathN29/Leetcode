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

unordered_map<int, int> count; 
int maxCount = 0;

vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> res;
    dfs(root);
    for(auto &e : count) {
    	if(e.second == maxCount) {
    		res.push_back(e.first);
    	}
    }
    return res; 
}

int dfs(TreeNode* root) {
	if(root == NULL) return 0;
	int s = dfs(root->left) + dfs(root->right) + root->val;
	maxCount = max(maxCount, ++count[s]);
	return s; 
} 

int main() {

}