// https://leetcode.com/problems/copy-list-with-random-pointer/
// Time - O(N), Space - O(1)

#include <iostream>

using namespace std; 

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter = head, *next;
        while(iter != NULL) {
            next = iter->next;
        

            Node* copy = new Node(iter->val);
            iter->next = copy;
            copy->next = next;

            iter = next;
        }

        iter = head;
        while(iter != NULL) {
            if(iter->random != NULL) {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }

        iter = head; 
        Node* pseudoHead = new Node(0);
        Node *copy, *copyIter = pseudoHead;

        while(iter != NULL) {
            next = iter->next->next;
            copy = iter->next; 
            copyIter->next = copy; 
            copyIter = copy;

            iter->next = next;
            iter = next;
        }
        return pseudoHead->next;
    }
};