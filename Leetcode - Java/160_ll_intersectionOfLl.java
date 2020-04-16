// https://leetcode.com/problems/intersection-of-two-linked-lists/

class ListNode {
	int val;
	ListNode next;
	ListNode(int x) {
		val = x;
		next = null;
	}
}

public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    	ListNode list1 = headA, list2 = headB;
    	if(list1 == null || list2 == null) return null;

    	while(list1 != null && list2 != null && list1 != list2) {
    		list1 = list1.next;
    		list2 = list2.next;
    		if(list1 == list2) return list1;
    		if(list1 == null) list1 = headB;
    		if(list2 == null) list2 = headA;
    	}
    	return list1;
    }
}