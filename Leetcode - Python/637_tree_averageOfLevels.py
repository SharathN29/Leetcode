# https://leetcode.com/problems/average-of-levels-in-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        if root is None:
            return []

        res = []
        queue = [root]

        while len(queue) != 0:
            size = len(queue)
            levelSum = 0
            for i in range(size):
                curr = queue.pop(0)
                levelSum += curr.val
                if curr.left is not None:
                    queue.append(curr.left)
                if curr.right is not None:
                    queue.append(curr.right)
            res.append(levelSum/size)
        return res
