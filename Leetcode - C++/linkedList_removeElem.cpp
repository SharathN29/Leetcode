#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode *sentinal = new ListNode(0);
    sentinal->next = head;

    ListNode *prev = sentinal, *cur = head, *toDel = nullptr;
    while(cur != NULL) {
        if(curr->val == val) {
            pre->next = cur->next;
            toDel = cur;
        } else pre = cur;

        cur = cur->next;

        if(toDel != nullptr) {
            delete toDel;
            toDel = nullptr;
        }
    }

    ListNode *ret = sentinal->next;
    delete sentinal;
    return ret;
}
