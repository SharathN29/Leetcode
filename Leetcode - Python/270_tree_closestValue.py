# https://leetcode.com/problems/closest-binary-search-tree-value/

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def closestValueRcr(self, root: TreeNode, target: float) -> int:
        def inorder(root: TreeNode) -> List[TreeNode]:
            return inorder(root.left) + [root.val] + inorder(root.right) if root else []
        return min(inorder(root), key=lambda x: abs(target - x))

    def closestValue(self, root: TreeNode, target: float) -> int:
        res = root.val
        while root:
            if abs(root.val - target) < abs(res - target):
                res = root.val
            root = root.left if target < root.val else root.right
        return res