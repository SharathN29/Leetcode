#include <iostream> 

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head, Node* rest = nullptr) {
        if(!head) return rest; 
        head->next = flatten(head->child, flatten(head->next, rest));
        if(head->next) head->next->prev = head; 
        head->child = nullptr;
        return head; 
    }   
};