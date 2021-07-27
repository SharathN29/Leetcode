# https://leetcode.com/problems/binary-tree-inorder-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        def traversal(node: TreeNode) -> None:
            if node is None: 
                return
            traversal(node.left)
            inorder.append(node.val)
            traversal(node.right)
        inorder = []
        traversal(root)
        
        return inorder