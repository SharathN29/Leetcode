// https://leetcode.com/problems/merge-two-sorted-lists/
// Time : O(n+m), Space : O(1)

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* preHead = new ListNode(-1);
    ListNode* prev = preHead;
    while(l1 != NULL || l2 != NULL) {
        if(l1->val <= l2->val){
            prev->next = l1;
            l1 = l1->next;
        } else if(l1->val > l2->val){
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    prev->next = l1 == NULL ? l2 : l1;
    return preHead->next;
}