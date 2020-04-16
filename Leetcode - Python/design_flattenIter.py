"""
Flatten Nested List Iterator : https://leetcode.com/problems/flatten-nested-list-iterator/
Author : Sharath Nagendra 

Passes all leetcode test cases as of Oct 12 2019
Runtime: 72 ms, faster than 49.50% of Python online submissions for Flatten Nested List Iterator.
Memory Usage: 17.5 MB, less than 48.39% of Python online submissions for Flatten Nested List Iterator.
"""
class NestedIterator(object):
    def __init__(self, nestedList):
        self.stack = nestedList[::-1]

    def next(self):
        return self.stack.pop().getInteger()

    def hasNext(self):
        while self.stack:
            top = self.stack[-1]
            if top.isInteger():
                return True
            self.stack = self.stack[:-1] + top.getList()[::-1]
        return False
