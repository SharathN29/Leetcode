// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    public ListNode swapNodes(ListNode head, int k) {
        int listLength = 0;
        ListNode curr = head; 
        
        while (curr != null) {
            listLength++;
            curr = curr.next;
        }
        
        ListNode front = head; 
        for (int i = 0; i < k - 1; i++) {
            front = front.next;
        }
        
        ListNode end = head;
        for (int i = 0; i < listLength - k; i++) {
            end = end.next;
        }
        
        int temp = front.val;
        front.val = end.val;
        end.val = temp;
        
        return head;
    }
}