// https://leetcode.com/problems/add-two-numbers/
// Time : O(max(m,n)), where m is size of l1, n is size of l2
// Space : O(max(m,n))

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode preHead(0), *p = &preHead;
    int carry = 0;
    while(l1 || l2 || carry){
        if(l1) carry += l1->val, l1 = l1->next;
        if(l2) carry += l2->val, l2 = l2->next;
        p->next = new ListNode(carry%10);
        carry = carry/10;
        p = p->next;
    }
    return preHead.next;
}