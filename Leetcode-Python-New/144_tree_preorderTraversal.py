# https://leetcode.com/problems/binary-tree-preorder-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        preorderList = []
        self.preorder(root, preorderList)
        return preorderList
    
    def preorder(self, node: TreeNode, preorderList: List[int]) -> None:
        if node is None:
            return
        preorderList.append(node.val)
        self.preorder(node.left, preorderList)
        self.preorder(node.right, preorderList)