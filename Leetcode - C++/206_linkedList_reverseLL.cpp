// https://leetcode.com/problems/reverse-linked-list/
// Time : O(N), Space : O(1)

#include <iostream>

using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    while(head){
        ListNode* nextNode = head->next;
        head->next = pre;
        pre = head;
        head = nextNode;
    }
    return pre;
}