# https://leetcode.com/problems/swap-nodes-in-pairs/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy = ListNode(-1)
        dummy.next = head
        prev = dummy
        
        while head and head.next:
            first, second = head, head.next
            
            prev.next = second
            first.next = second.next
            second.next = first
            
            prev, head = first, first.next
            
        return dummy.next