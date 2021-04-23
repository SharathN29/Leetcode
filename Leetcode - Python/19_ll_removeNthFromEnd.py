# https://leetcode.com/problems/remove-nth-node-from-end-of-list/

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        pre = ListNode(-1)
        pre.next = head
        d1 = d2 = pre

        for i in range(n):
            d1 = d1.next

        while d1.next:
            d1 = d1.next
            d2 = d2.next

        d2.next = d2.next.next
        return pre.next
