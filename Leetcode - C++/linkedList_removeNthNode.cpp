// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Time : O(N), Space : O(1)

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *slow = dummy, *fast = dummy;
    for(int i = 0; i < n; i++)
        fast = fast->next;
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}

int main() {

}