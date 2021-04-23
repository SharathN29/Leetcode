# https://leetcode.com/problems/remove-duplicates-from-sorted-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        newHead = head
        while newHead and newHead.next:
            if newHead.val == newHead.next.val:
                newHead.next = newHead.next.next
            else:
                newHead = newHead.next
        return head
