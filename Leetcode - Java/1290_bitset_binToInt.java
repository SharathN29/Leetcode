// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    // public int getDecimalValue(ListNode head) {
    //     int ans = 0;
    //     while(head != null) {
    //         ans = ans*2 + head.val;
    //         head = head.next;
    //     }
    //     return ans; 
    // }
    
    public int getDecimalValue(ListNode head) {
        int ans = 0;
        while(head != null) {
            ans = (ans << 1) | head.val;
            head = head.next;
        }
        return ans; 
    }
}