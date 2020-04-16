// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
 
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res; 
        if(!root) return res;
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty()) {
            int len = q.size();
            vector<int> level(len);
            for(int i = 0; i < len; i++) {
                Node* temp = q.front();
                q.pop();
                level[i] = temp->val;
                for(Node* child : temp->children) {
                    q.push(child);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};