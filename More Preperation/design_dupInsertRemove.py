"""
Insert Delete GetRandom O(1) - Duplicates allowed : https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 7 2019
Runtime: 92 ms, faster than 90.43% of Python online submissions for Insert Delete GetRandom O(1) - Duplicates allowed.
Memory Usage: 17.8 MB, less than 100.00% of Python online submissions for Insert Delete GetRandom O(1) - Duplicates allowed.
"""
import random
import collections

class RandomizedCollection(object):

    def __init__(self):
        self.vals, self.idxs = [], collections.defaultdict(set)
        

    def insert(self, val):
        self.vals.append(val)
        self.idxs[val].add(len(self.vals) - 1)
        return len(self.idxs[val]) == 1
        

    def remove(self, val):
        if self.idxs[val]:
            out, ins = self.idxs[val].pop(), self.vals[-1]
            self.vals[out] = ins
            if self.idxs[ins]:
                self.idxs[ins].add(out)
                self.idxs[ins].discard(len(self.vals) - 1)
            self.vals.pop()
            return True
        return False 

    def getRandom(self):
        return random.choice(self.vals)

rc = RandomizedCollection()
print(rc.insert(1))
print(rc.insert(1))
print(rc.insert(2))
print(rc.getRandom())
print(rc.remove(1))
print(rc.getRandom())