// https://leetcode.com/problems/reverse-linked-list/

class ListNode {
	int val;
	ListNode next;
	ListNode(int x) {
		val = x;
		next = null;
	}
}

class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null) return null;
        ListNode pre = null;

        while(head != null) {
        	ListNode nextNode = head.next; 
        	head.next = pre; 
        	pre = head; 
        	head = nextNode;
        }
        return pre;
    }
}