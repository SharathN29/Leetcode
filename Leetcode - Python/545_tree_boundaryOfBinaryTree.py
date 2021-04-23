# https://leetcode.com/problems/boundary-of-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.nodes = []

    def boundaryOfBinaryTree(self, root: TreeNode) -> List[int]:
        if not root:
            return self.nodes

        self.nodes.append(root.val)
        self.leftBoundary(root.left)
        self.leaves(root.left)
        self.leaves(root.right)
        self.rightBoundary(root.right)

        return self.nodes

    def leftBoundary(self, root: TreeNode) -> None:
        if root is None or (root.left is None and root.right is None):
            return
        self.nodes.append(root.val)
        if root.left is None:
            self.leftBoundary(root.right)
        else:
            self.leftBoundary(root.left)

    def rightBoundary(self, root: TreeNode) -> None:
        if root is None or (root.left is None and root.right is None):
            return
        if root.right is None:
            self.rightBoundary(root.left)
        else:
            self.rightBoundary(root.right)
        self.nodes.append(root.val)

    def leaves(self, root: TreeNode) -> None:
        if root is None:
            return
        if root.left is None and root.right is None:
            self.nodes.append(root.val)
            return
        self.leaves(root.left)
        self.leaves(root.right)
