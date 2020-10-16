// https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/

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
    public ListNode deleteNodes(ListNode head, int m, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode t = new ListNode(0);
        t.next = head;
        while (t != null && t.next != null) {
            for (int i = 0; i < m; i++) {
                if (t == null || t.next == null) {
                    return dummy.next;
                }
                t = t.next;
            } 
            for (int i = 0; i < n; i++) {
                if (t == null || t.next == null) {
                    return dummy.next;
                }
                t.next = t.next.next;
            }
        }   
        return dummy.next;
    }
}