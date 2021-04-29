// https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/

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
    public ListNode deleteDuplicatesUnsorted(ListNode head) {
        if (head == null || head.next == null) return head;
        Set<Integer> uniqueListValues = new HashSet();
        Set<Integer> duplicateListValues = new HashSet();
        
        ListNode node = head; 
        
        while (node != null) {
            if (uniqueListValues.contains(node.val)) {
                duplicateListValues.add(node.val);
            } else {
                uniqueListValues.add(node.val);
            }
            node = node.next;
        } 
        
        ListNode preHead = new ListNode(-1);
        preHead.next = head;
        ListNode preNode = preHead;
        node = head; 
        while (node != null) {
            if (duplicateListValues.contains(node.val)) {
                preNode.next = node.next;  
            } else {
                preNode = preNode.next;
            }
            node = node.next;
        }
        
        return preHead.next;
    }
}
