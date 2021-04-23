# https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head is None: return None
        if head.next is None: return head

        val = head.val
        nextNode = head.next

        if nextNode.val != val:
            head.next = self.deleteDuplicates(nextNode)
            return head
        else:
            while nextNode and nextNode.val == val:
                nextNode = nextNode.next 
            return self.deleteDuplicates(nextNode)