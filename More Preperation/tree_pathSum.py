"""
Path Sum : https://leetcode.com/problems/path-sum/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 11 2019
Runtime: 28 ms, faster than 89.83% of Python online submissions for Path Sum.
Memory Usage: 15.6 MB, less than 6.82% of Python online submissions for Path Sum.
"""
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        if not root:
            return False
        sum -= root.val
        if not root.left and not root.right:
            return sum == 0
        return self.hasPathSum(root.left, sum) or self.hasPathSum(root.right, sum)


