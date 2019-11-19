"""
Insert Delete GetRandom O(1) : https://leetcode.com/problems/insert-delete-getrandom-o1/
Author : Sharath Nagendra 

Passes all leetcode test cases as of Oct 7 2019
Runtime: 92 ms, faster than 87.73% of Python online submissions for Insert Delete GetRandom O(1).
Memory Usage: 16.2 MB, less than 100.00% of Python online submissions for Insert Delete GetRandom O(1).
"""
import random

class RandomizedSet(object):
    def __init__(self):
        self.nums, self.pos = [], {}

    def insert(self, val):
        if val not in self.pos:
            self.nums.append(val)
            self.pos[val] = len(self.nums)-1
            return True
        return False
    
    def remove(self, val):
        if val in self.pos:
            idx, last = self.pos[val], self.nums[-1]
            self.nums[idx], self.pos[last] = last, idx
            self.nums.pop(); self.pos.pop(val, 0)
            return True
        return False
    
    def getRandom(self):
        return self.nums[random.randint(0, len(self.nums)-1)]

rc = RandomizedSet()
print(rc.insert(1))
print(rc.remove(2))
print(rc.insert(2))
print(rc.getRandom())