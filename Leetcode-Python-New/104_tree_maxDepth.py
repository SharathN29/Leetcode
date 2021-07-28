# https://leetcode.com/problems/maximum-depth-of-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        
        max_left_depth = self.maxDepth(root.left)
        max_right_depth = self.maxDepth(root.right)
        
        return max(max_left_depth, max_right_depth) + 1