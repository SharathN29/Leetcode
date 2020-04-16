#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private: 
    int maxSum = INT_MIN;
    
    int maxGain(TreeNode* node) {
        if(node == NULL) return 0;
        
        int leftGain = max(maxGain(node->left),0);
        int rightGain = max(maxGain(node->right),0);
        
        int priceNewPath = node->val + leftGain + rightGain;
        maxSum = max(maxSum, priceNewPath);
        
        return node->val + max(leftGain, rightGain);
    }
public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};

int main() {
	
}