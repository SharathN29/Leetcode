"""
Binary Tree Zigzag Level Order Traversal : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 8 2019
Runtime: 16 ms, faster than 87.06% of Python online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 12.2 MB, less than 14.28% of Python online submissions for Binary Tree Zigzag Level Order Traversal.
"""
import collections

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def zigzagLevelOrder(self, root):
        queue = collections.deque([root])
        res = []
        while queue:
            r = []
            for _ in range(len(queue)):
                q = queue.popleft() 
                if q:
                    r.append(q.val)
                    queue.append(q.left)
                    queue.append(q.right)
            r = r[::-1]if len(res) % 2 else r
            if r:
                res.append(r)
        return res