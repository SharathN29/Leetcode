// https://leetcode.com/problems/swap-nodes-in-pairs/
// Time : O(n), Space : O(n)

#include <iostream>

using namespace std; 

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
        	return head;

        ListNode* firstNode = head;
        ListNode* secondNode = head->next;

        firstNode->next = swapPairs(secondNode->next);
        secondNode->next = firstNode;

        return secondNode;
    }
};