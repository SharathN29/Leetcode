"""
Binary Tree Maximum Path Sum : https://leetcode.com/problems/binary-tree-maximum-path-sum/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 12 2019
Runtime: 96 ms, faster than 85.42% of Python3 online submissions for Binary Tree Maximum Path Sum.
Memory Usage: 22.1 MB, less than 5.55% of Python3 online submissions for Binary Tree Maximum Path Sum.
"""
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def maxPathSum(self, root):
        def maxGain(node):
            nonlocal maxSum
            if not node:
                return 0
            leftGain = max(maxGain(node.left),0)
            rightGain = max(maxGain(node.right),0)
            priceNewPath = node.val + leftGain + rightGain
            maxSum = max(maxSum,priceNewPath)
            return node.val+max(leftGain, rightGain)
        maxSum = -float('inf')
        maxGain(root)
        return maxSum