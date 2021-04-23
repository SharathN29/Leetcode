// https://leetcode.com/problems/merge-in-between-linked-lists/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode l1 = new ListNode(-1), l2 = new ListNode(-1);
        l1.next = list1; l2.next = list1;
        
        while (l1.next.val != a && l1 != null) {
            l1 = l1.next;
        }
        
        while (l2.next.val != b && l2 != null) {
            l2 = l2.next;
        }
        l2 = l2.next.next;
        
        l1.next = list2;
        l1 = list2;
        
        while (l1.next != null) {
            l1 = l1.next;
        }
        l1.next = l2;
        
        return list1;
    }
}