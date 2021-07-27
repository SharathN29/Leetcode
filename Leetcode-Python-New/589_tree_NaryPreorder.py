# https://leetcode.com/problems/n-ary-tree-preorder-traversal/

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        def preorder(node: 'Node') -> None:
            if node is None:
                return 
            traversal.append(node.val)
            for child in node.children:
                preorder(child)
        traversal = []
        preorder(root)
        return traversal