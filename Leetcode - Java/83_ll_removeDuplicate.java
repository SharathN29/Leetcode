// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode new_head = head; 
        while(new_head != null && new_head.next != null) {
            if(new_head.val == new_head.next.val) {
                new_head.next = new_head.next.next;
            } else {
                new_head = new_head.next;
            }
        }
        return head;
    }
}