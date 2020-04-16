"""
Maximum Average Subtree : https://leetcode.com/problems/maximum-average-subtree/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 13 2019
Runtime: 36 ms, faster than 95.40% of Python online submissions for Maximum Average Subtree.
Memory Usage: 17.7 MB, less than 100.00% of Python online submissions for Maximum Average Subtree.
"""
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def maximumAverageSubtree(self, root):
		self.res = 0
		def helper(root):
			if not root: return [0, 0.0]
			n1, s1 = helper(root.left)
			n2, s2 = helper(root.right)
			n = n1 + n2 + 1
			s = s1 + s2 + root.val
			self.res = max(self.res, s/n)
			return [n,s]
		helper(root)
		return self.res