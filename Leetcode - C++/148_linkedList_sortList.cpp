// https://leetcode.com/problems/sort-list/
// Time - O(nlogn)
// Space - O(n), it uses additional space for the call stack of the recursive function, so it cannot be considered as a constant
// space solution
// Need to think on a iterative merge sort solution, which doesnt use call stack for the recursion. 

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) 
			return head;
		ListNode *fast = head->next->next;
		ListNode *slow = head;
		while(fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *r = sortList(slow->next);
		slow->next = nullptr; 
		ListNode *l = sortList(head);
		return merge(l,r);
    }
	
	ListNode *merge(ListNode *l, ListNode *r) {
		ListNode *dummy = new ListNode(0), *node;
		node = dummy; 
		
		while(l && r) {
			if(l->val <= r->val) {
				node->next = l;
				l = l->next;
			} else {
				node->next = r;
				r = r->next;
			}
			node = node->next;
		}
		if(l) node->next = l;
		else node->next = r;
		return dummy->next;
	}
};

int main() {
	
}