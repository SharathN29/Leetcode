// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
        if(head == null) return null;
        if(head.next == null) return head; 
        
        int val = head.val;
        ListNode nextNode = head.next; 
        
        if(nextNode.val != val) {
            head.next = deleteDuplicates(nextNode);
            return head; 
        } else {
            while(nextNode != null && nextNode.val == val) nextNode = nextNode.next;
            return deleteDuplicates(nextNode);
        }
    }
}