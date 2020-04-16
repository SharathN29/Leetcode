"""
Two Sum IV - Input is a BST : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
Author : Sharath Nagendra

Passes all leetcode test cases as on Oct 4 2019
Runtime: 60 ms, faster than 95.78% of Python online submissions for Two Sum IV - Input is a BST.
Memory Usage: 16 MB, less than 100.00% of Python online submissions for Two Sum IV - Input is a BST.
"""
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def findTarget(self, root, k):
        if not root: return False
        bfs, s = [root], set()
        for i in bfs:
            if k-i.val in s: return True
            s.add(i.val)
            if i.left: bfs.append(i.left)
            if i.right: bfs.append(i.right)
        return False