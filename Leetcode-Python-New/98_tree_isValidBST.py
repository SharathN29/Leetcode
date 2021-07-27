# https://leetcode.com/problems/validate-binary-search-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        return self.isValid(root, None, None)
    
    def isValid(self, node: TreeNode, minNode: TreeNode, maxNode: TreeNode) -> bool:
        if node is None:
            return True
        if minNode and node.val <= minNode.val or maxNode and node.val >= maxNode.val:
            return False
        return self.isValid(node.left, minNode, node) and self.isValid(node.right, node, maxNode)