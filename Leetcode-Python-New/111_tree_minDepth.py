# https://leetcode.com/problems/minimum-depth-of-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    min_depth = float('inf')
    def minDepth(self, root: TreeNode) -> int:
        if root is None: 
            return 0
        curr_depth = 1
        self.calculate_min_depth(root, curr_depth)
        return self.min_depth
    
    def calculate_min_depth(self, node: TreeNode, curr_depth: int) -> None:
        if node is None:
            return
        if node.left is None and node.right is None: 
            self.min_depth = min(self.min_depth, curr_depth)
            
        self.calculate_min_depth(node.left, curr_depth + 1)
        self.calculate_min_depth(node.right, curr_depth + 1)