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

class Solution {
int postIndex;
unordered_map<int, int> map;

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;
        int index = 0;
        for(int val : inorder)
            map[val] = index++;
        return helper(0, inorder.size()-1, inorder, postorder);
    }

    TreeNode* helper(int left, int right, vector<int>& inorder, vector<int>& postorder) {
        if(left > right) return NULL;

        int rootVal = postorder[postIndex];
        TreeNode* root = new TreeNode(rootVal);
        int index = map[rootVal];
        postIndex--;

        root->right = helper(index+1, right, inorder, postorder);
        root->left = helper(left, index-1, inorder, postorder);
        return root;
    }
};

int main() {
	vector<int> inorder = {9,3,15,20,7}, postorder = {9,15,7,20,3};

}

