#include <iostream>
#include <queue>

using namespace std; 

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> q;
        if(!root) return NULL;
        q.push(root);
        while(!q.empty()){
            int qLen = q.size();
            for(int i = 0; i < qLen; i++){
                Node* temp = q.front();
                q.pop();
                if(i+1 == qLen)
                    temp->next = NULL;
                else temp->next = q.front(); 
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right); 
            }
        }
        return root;
    }
};