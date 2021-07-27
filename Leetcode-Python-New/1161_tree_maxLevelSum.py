# https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        if root is None: 
            return -1
        
        queue = deque([root])
        maxLevelSum, maxLevel, currLevel = float('-inf'), 0, 0
        
        while queue:
            size = len(queue)
            levelSum = 0
            for i in range(size):
                curr = queue.popleft()
                levelSum += curr.val
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)
            if levelSum > maxLevelSum:
                maxLevelSum = levelSum 
                maxLevel = currLevel + 1
            currLevel += 1
        
        return maxLevel