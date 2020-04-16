// https://leetcode.com/problems/reverse-linked-list-ii/
// Time : O(N), Spcace - O(1)

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode *dummy = new ListNode(0), *pre = dummy, *curr;
    dummy->next = head;

    for(int i = 0; i < m-1; i++)
        pre = pre->next;

    curr = pre->next;
    for(int i = 0; i < n-m; i++) {
        pre->next = curr->next;
        curr->next = curr->next->next;
        pre->next->next = temp;
    }
    return dummy->next;
}

int main() {

}
