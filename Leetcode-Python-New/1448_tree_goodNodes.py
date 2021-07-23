# https://leetcode.com/problems/count-good-nodes-in-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    count = 0
    def goodNodes(self, root: TreeNode) -> int:
        if root is None:
            return self.count
        self.countGoodNodes(root, float("-inf"))
        return self.count
    
    def countGoodNodes(self, node: TreeNode, currMax: int) -> None:
        if node is None: 
            return 
        
        if node.val >= currMax:
            self.count += 1
            currMax = node.val
            
        self.countGoodNodes(node.left, currMax)
        self.countGoodNodes(node.right, currMax)
        