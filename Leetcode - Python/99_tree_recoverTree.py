# https://leetcode.com/problems/recover-binary-search-tree/

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.firstElem = self.secondElem = None
        self.prevElem = TreeNode(-2147483648)

    def recoverTree(self, root: TreeNode) -> None:
        self.traverse(root)
        self.firstElem.val, self.secondElem.val = self.secondElem.val, self.firstElem.val

    def traverse(self, root: TreeNode) -> None:
        if root is None:
            return

        self.traverse(root.left)
        if self.firstElem is None and self.prevElem.val > root.val:
            self.firstElem = self.prevElem
        if self.firstElem is not None and self.prevElem.val > root.val:
            self.secondElem = root
        self.prevElem = root
        self.traverse(root.right)
