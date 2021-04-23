# https://leetcode.com/problems/merge-k-sorted-lists/

from queue import PriorityQueue


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        dummy = curr = ListNode(None)
        q = PriorityQueue(maxsize=len(lists))

        for idx, node in enumerate(lists):
            if node:
                q.put((node.val, idx, node))

        while not q.empty():
            poppedNode = q.get()
            curr.next = poppedNode[2]
            curr = curr.next
            if curr.next:
                q.put((curr.next.val, poppedNode[1], curr.next))

        return dummy.next
