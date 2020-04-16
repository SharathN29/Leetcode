"""
Binary Tree Paths : https://leetcode.com/problems/binary-tree-paths/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 11 2019
Runtime: 24 ms, faster than 31.90% of Python online submissions for Binary Tree Paths.
Memory Usage: 11.9 MB, less than 31.58% of Python online submissions for Binary Tree Paths.
"""
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        def constructPaths(root, path):
            if root: 
                path += str(root.val)
                if not root.left and not root.right: 
                    paths.append(path)
                else:
                    path += '->'
                    constructPaths(root.left, path)
                    constructPaths(root.right, path)
        paths = []
        constructPaths(root,'')
        return paths 
