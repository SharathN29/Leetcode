// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        return sortedListToBST(head, null);
    }
    
    private TreeNode sortedListToBST(ListNode head, ListNode tail) {
        if (head == tail) 
            return null;
        
        ListNode mid = head, temp = head; 
        while (temp != tail && temp.next != tail) {
            mid = mid.next;
            temp = temp.next.next;
        }
        
        TreeNode root = new TreeNode(mid.val);
        root.left = sortedListToBST(head, mid);
        root.right = sortedListToBST(mid.next, tail);
        
        return root;
    }
}