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
        
        averages = []
        queue = deque([root])
        
        while queue:
            sum_of_nodes = 0
            num_of_nodes = len(queue)
            
            for i in range(num_of_nodes):
                curr = queue.popleft()
                sum_of_nodes += curr.val
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)
            averages.append(sum_of_nodes / num_of_nodes)
        
        return averages