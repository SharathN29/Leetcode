# https://leetcode.com/problems/rotate-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head is None or k is 0:
            return head
        
        dummy = ListNode(-1)
        dummy.next = head
        slow = fast = dummy
        
        i = 0
        while fast.next: 
            i += 1
            fast = fast.next
            
        for j in range(0, i - k % i):
            slow = slow.next
            
        fast.next = dummy.next
        dummy.next = slow.next
        slow.next = None
        
        return dummy.next