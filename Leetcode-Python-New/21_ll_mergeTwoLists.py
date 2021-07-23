# https://leetcode.com/problems/merge-two-sorted-lists/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        res = ListNode(-1)
        pre = res
        
        while l1 is not None and l2 is not None:
            if l1.val < l2.val:
                pre.next = l1
                l1 = l1.next
            else: 
                pre.next = l2
                l2 = l2.next
            pre = pre.next
            
        pre.next = l1 if l2 is None else l2
        
        return res.next
        