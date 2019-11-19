"""
Path Sum II : https://leetcode.com/problems/path-sum-ii/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 11 2019
Runtime: 28 ms, faster than 95.38% of Python online submissions for Path Sum II.
Memory Usage: 18.2 MB, less than 28.57% of Python online submissions for Path Sum II.
"""
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        res = []
        if not root:
            return res
        self.dfs(root, sum, [], res)
        return res
    
    def dfs(self, root, sum, ls, res):
        if not root.left and not root.right and sum-root.val == 0:
            ls.append(root.val)
            res.append(ls)
        if root.left:
            self.dfs(root.left, sum-root.val, ls+[root.val], res)
        if root.right:
            self.dfs(root.right, sum-root.val, ls+[root.val], res)