# https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        dummy = ListNode(-1)
        dummy.next = head
        
        prev = dummy
        
        while head and head.next:
            if head.val == head.next.val:
                prev.next = self.findNextNode(head, head.val)
                head = prev.next
            else:
                head = head.next
                prev = prev.next
                
        return dummy.next
    
    def findNextNode(self, head: ListNode, val: int) -> ListNode:
        while head and head.val == val:
            head = head.next
        return head