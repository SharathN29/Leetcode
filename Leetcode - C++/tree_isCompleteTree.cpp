#include <iostream>
#include <queue>

using namespace std; 

bool isCompleteTree(TreeNode* root) {
	bool seenNull = false; 
	queue<TreeNode *> q;
	q.push(root);

	while(!q.empty()) {
		TreeNode *temp = q.top();
		q.pop();

		if(temp == NULL)
			seenNull = true;
		else {
			if(seenNull)
				return false;

			q.push(temp->left);
			q.push(temp->right);
		}
	}
	return true;
}