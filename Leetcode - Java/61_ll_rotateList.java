// https://leetcode.com/problems/rotate-list/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
    	if(head == null || head.next == null) return head; 

        ListNode dummyhead = new ListNode(0);
        dummyhead.next = head; 
        ListNode slow = dummyhead, fast = dummyhead;

        int i;
        for(i = 0; fast.next != null; i++) {
        	fast = fast.next;
        }

        for(int j = i-k%i; j > 0; j--) {
        	slow = slow.next;
        }

        fast.next = dummyhead.next; 
        dummyhead.next = slow.next; 
        slow.next = null;

        return dummyhead.next;
    }
}