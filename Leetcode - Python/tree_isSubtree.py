"""
Subtree of Another Tree : https://leetcode.com/problems/subtree-of-another-tree/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 8 2019
Runtime: 244 ms, faster than 74.52% of Python online submissions for Subtree of Another Tree.
Memory Usage: 13 MB, less than 20.00% of Python online submissions for Subtree of Another Tree.
"""
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isSubtree(self, s, t):
        if not t:
            return True
        
        def checkTree(root1, root2):
            if not root1 and not root2:
                return True
            elif root1 and not root2 or not root1 and root2:
                return False

            if root1.val != root2.val:
                return False
            
            return checkTree(root1.left, root2.left) and checkTree(root1.right, root2.right)

        def dfs(s,t):
            if not s:
                return False
            if s.val == t.val and checkTree(s,t):
                return True
            return dfs(s.left,t) or dfs(s.right,t)
        
        return dfs(s,t) 