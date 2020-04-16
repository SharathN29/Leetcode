// https://leetcode.com/problems/palindrome-linked-list/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null) 
        	return true;

        ListNode slow = head, fast = head; 
        while(fast.next != null && fast.next.next != null) {
        	slow = slow.next;
        	fast = fast.next.next;
        }

        slow.next = reverseLL(slow.next);
        slow = slow.next;

        while(slow != null) {
        	if(slow.val != head.val)
        		return false; 
        	slow = slow.next;
        	head = head.next; 
        }
        return true; 
    }

    private ListNode reverseLL(ListNode head) {
    	ListNode pre = null; 

    	while(head != null) {
    		ListNode nextnode = head.next;
    		head.next = pre; 
    		pre = head;
    		head = nextnode; 
    	}
    	return pre; 
    } 
}