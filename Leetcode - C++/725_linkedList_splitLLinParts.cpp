// https://leetcode.com/problems/split-linked-list-in-parts/

#include <iostream>

using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode *> parts(k, nullptr);
        int len = 0;
        for(ListNode* node = root; node; node = node->next) {
            len++;
        }
        int n = len/k, r = len % k;
        ListNode* node = root, *prev = nullptr;
        for(int i = 0; node; i++, r--) {
            parts[i] = node; 
            for(int j = 0; j < n + (r>0); j++) {
                prev = node; 
                node = node->next; 
            }
            prev->next = nullptr; 
        }
        return parts;
    }
};