# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

from queue import PriorityQueue

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        class Compare:
            def __init__(self, node: ListNode) -> None:
                self.node = node
                
            def __lt__(self, other) -> bool:
                return self.node.val < other.node.val
            
        head = point = ListNode(0)
        q = PriorityQueue()
        for l in lists: 
            if l:
                q.put(Compare(l))
                
        while not q.empty():
            node = q.get().node
            point.next = node
            point = point.next
            node = node.next
            if node: 
                q.put(Compare(node))
                
        return head.next