// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class ListNode {
	int val;
	ListNode next;
	ListNode(int x) {
		val = x;
		next = null;
	}
}

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
    	if(head == null) return null;
    	ListNode pre = new ListNode(-1);
    	pre.next = head;
    	ListNode slow = pre, fast = pre; 

    	for(int i = 0; i < n; i++) 
    		fast = fast.next;

    	while(fast.next != null) {
    		slow = slow.next;
    		fast = fast.next;
    	} 

    	slow.next = slow.next.next;
    	return pre.next;
    }
}