// https://leetcode.com/problems/equal-tree-partition/

#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> map;
        int sum = treeSum(root, map);
        return sum % 2 == 0 && (sum == 0 ? map[0] > 1: map[sum/2] > 0);
    }

    int treeSum(TreeNode* node, unordered_map<int, int>& map) {
        if(!node) return 0;
        int sum = node->val + treeSum(node->left, map) + treeSum(node->right, map);
        map[sum]++;
        return sum;
    }
};

int main() {

}