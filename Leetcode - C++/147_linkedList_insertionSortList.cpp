// https://leetcode.com/problems/insertion-sort-list/
// Time - O(N^2)

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *pre = dummy, *curr = head; 
		while(curr) {
			if((curr->next) && (curr->next->val < cuur->val)) {
				while((pre->next) && (pre->next->val < curr->next->val)) {
					pre = pre->next;
				}
				ListNode *temp = pre->next;
				pre->next = curr->next;
				curr->next = curr->next->next;
				pre->next->next = temp;
				pre = dummy;
			} else {
				curr = curr->next;
			}
		}
		return dummy->next;
    }
};

int main() {
	
}