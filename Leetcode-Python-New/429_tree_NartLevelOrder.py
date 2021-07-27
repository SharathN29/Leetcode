# https://leetcode.com/problems/n-ary-tree-level-order-traversal/

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if root is None:
            return []
        
        queue = deque([root])
        level_order = []
        
        while queue:
            size = len(queue)
            level = []
            for i in range(size):
                curr = queue.popleft()
                level.append(curr.val)
                for child in curr.children:
                    queue.append(child)
            level_order.append(level)
        return level_order
        