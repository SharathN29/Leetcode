"""
Path Sum III : https://leetcode.com/problems/path-sum-iii/
Author : Sharath Nagendra 

Passes all leetcode test cases as of Oct 11 2019
Runtime: 36 ms, faster than 93.79% of Python online submissions for Path Sum III.
Memory Usage: 12.9 MB, less than 72.73% of Python online submissions for Path Sum III.
"""
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        self.result = 0
        self.helper(root, sum, 0, {0:1})
        return self.result

    def helper(self, root, target, sumSoFar, cache):
        if root:
            complement = sumSoFar+root.val - target
            if complement in cache:
                self.result += cache[complement]
            cache.setdefault(sumSoFar+root.val,0)
            cache[sumSoFar+root.val] += 1
            self.helper(root.left, target, sumSoFar+root.val, cache)
            self.helper(root.right, target, sumSoFar+root.val, cache)
            cache[sumSoFar+root.val] -= 1
        return

