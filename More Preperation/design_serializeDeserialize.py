"""
Serialize and Deserialize Binary Tree : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 5 2019
Runtime: 100 ms, faster than 77.52% of Python online submissions for Serialize and Deserialize Binary Tree.
Memory Usage: 22 MB, less than 46.15% of Python online submissions for Serialize and Deserialize Binary Tree.
"""
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:
    def serialize(self, root):
        def doit(node):
            if node:
                vals.append(str(node.val))
                doit(node.left)
                doit(node.right)
            else:
                vals.append('#')
        vals = []
        doit(root)
        return ' '.join(vals)

    def deserialize(self, data):
        def doit():
            val = next(vals)
            if val == '#':
                return None
            node = TreeNode(int(val))
            node.left = doit()
            node.right = doit()
            return node
        vals = iter(data.split())
        return doit()