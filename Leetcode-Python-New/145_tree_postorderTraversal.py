# https://leetcode.com/problems/binary-tree-postorder-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        def postorder(node: TreeNode) -> None:
            if node is None:
                return
            postorder(node.left)
            postorder(node.right)
            postorderList.append(node.val)
        postorderList = []
        postorder(root)
        return postorderList