// https://leetcode.com/problems/linked-list-cycle-ii/

class ListNode {
	int val;
	ListNode next;
	ListNode(int x) {
		val = x;
		next = null;
	}
}

public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null || head.next == null) return null;

        ListNode firstPtr = head, secondPtr = head;
        boolean hasCycle = false; 

        while(firstPtr != null && secondPtr != null) {
        	firstPtr = firstPtr.next;
        	if(secondPtr.next == null) return null;
        	secondPtr = secondPtr.next.next;
        	if(firstPtr == secondPtr) {
        		hasCycle = true;
        		break;
        	}
        }

        if(!hasCycle) return false; 
        firstPtr = head;
        while(firstPtr != secondPtr) {
        	firstPtr = firstPtr.next;
        	secondPtr = secondPtr.next;
        }

        return firstPtr;
    }
}