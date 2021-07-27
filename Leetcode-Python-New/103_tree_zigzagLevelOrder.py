# https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        
        zigzag = []
        queue = deque([root])
        is_left_to_right = True
        
        while queue:
            curr_level = []
            size = len(queue)
            
            for i in range(size):
                curr_node = queue.popleft()
                curr_level.append(curr_node.val) if is_left_to_right else curr_level.insert(0, curr_node.val)
                if curr_node.left:
                    queue.append(curr_node.left)
                if curr_node.right:
                    queue.append(curr_node.right)
            zigzag.append(curr_level)
            is_left_to_right = not is_left_to_right
            
        return zigzag