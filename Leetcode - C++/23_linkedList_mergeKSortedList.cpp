// https://leetcode.com/problems/merge-k-sorted-lists/
// Time - O(nlogk)

#include <iostream>
#include <queue>

using namespace std; 


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {

	struct compare {
		bool operator() (int l1, int l2) {
			return l1 > l2;
		}
	};

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	priority_queue<int, vector<int>, compare> pq;
        for(ListNode *head : lists) {
            while(head != NULL) {
                pq.push(head->val);
                head = head->next; 
            }
        }
        
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy; 
        while(!pq.empty()) {
            head->next = new ListNode(pq.top());
            pq.pop();
            head = head->next; 
        }
        
        return dummy->next;
    }
};