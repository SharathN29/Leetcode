"""
Copy List with Random Pointer : https://leetcode.com/problems/copy-list-with-random-pointer/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 7 2019
Runtime: 392 ms, faster than 48.06% of Python online submissions for Copy List with Random Pointer.
Memory Usage: 14.6 MB, less than 50.00% of Python online submissions for Copy List with Random Pointer.
"""
class Node(object):
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
    
class Solution(object):
    def __init__(self):
        self.visitedHash = {}

    def copyRandomListRec(self, head):
        if head == None:
            return None
        
        if head in self.visitedHash:
            return self.visitedHash[head]

        node = Node(head.val, None, None)

        self.visitedHash[head] = node

        node.next = self.copyRandomListRec(head.next)
        node.random = self. copyRandomListRec(head.random)

        return node