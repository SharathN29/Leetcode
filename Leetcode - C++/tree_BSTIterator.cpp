#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
	queue<int> q;
private:
	void inOrder(TreeNode* root) {
		if(!root) return;
		inOrder(root->left);
		q.push(root->val);
		inOrder(root->right);
	}
public:
    BSTIterator(TreeNode* root) {
    	inOrder(root);
    }
    
    /** @return the next smallest number */
    int next() {
       int max = q.front();
       q.pop();
       return max; 
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }
};