# https://leetcode.com/problems/reverse-linked-list-ii/

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        dummy = ListNode(0)
        pre = dummy
        dummy.next = head

        for i in range(m - 1):
            pre = pre.next

        curr = pre.next

        for i in range(n - m):
            temp = pre.next
            pre.next = curr.next
            curr.next = curr.next.next
            pre.next.next = temp

        return dummy.next
