# https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque


class Solution:
    def findNearestRightNode(self, root: TreeNode, u: TreeNode) -> TreeNode:
        if root is None:
            return None

        q = deque([root, None, ])
        while q:
            curr = q.popleft()

            if curr == u:
                return q.popleft()

            if curr:
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)

            else:
                if q:
                    q.append(None)
