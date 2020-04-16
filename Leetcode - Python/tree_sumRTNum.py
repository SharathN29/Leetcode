"""
Sum root to leaf numbers : https://leetcode.com/problems/sum-root-to-leaf-numbers/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 12 2019
Runtime: 20 ms, faster than 60.78% of Python online submissions for Sum Root to Leaf Numbers.
Memory Usage: 12 MB, less than 68.18% of Python online submissions for Sum Root to Leaf Numbers.
"""
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def sumNumbers(self, root):
        if not root:
            return 0
        stack, res = [(root, root.val)], 0
        while stack:
            node, value = stack.pop()
            if node:
                if not node.left and not node.right:
                    res += value
                if node.right:
                    stack.append((node.right, value*10+node.right.val))
                if node.left:
                    stack.append((node.left, value*10+node.left.val))
        return res