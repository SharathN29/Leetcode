"""
Longest Univalued Path : https://leetcode.com/problems/longest-univalue-path/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 11 2019
Runtime: 444 ms, faster than 56.25% of Python online submissions for Longest Univalue Path.
Memory Usage: 18.8 MB, less than 54.55% of Python online submissions for Longest Univalue Path.
"""
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def longestUnivaluePath(self, root):
        self.ans = 0

        def arrowLength(root):
            if not root: return 0
            leftLength = arrowLength(root.left)
            rightLength = arrowLength(root.right)
            leftArrow = rightArrow = 0
            if root.left and root.left.val == root.val:
                leftArrow = leftLength + 1
            if root.right and root.right.val == root.val:
                rightArrow = rightLength + 1
            self.ans = max(self.ans, leftArrow+rightArrow)
            return max(leftArrow, rightArrow)

        arrowLength(root)
        return self.ans