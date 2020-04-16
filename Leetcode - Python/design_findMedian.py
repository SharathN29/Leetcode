"""
Find Median from Data Stream : https://leetcode.com/problems/find-median-from-data-stream/ 
Author : Sharath Nagendra

Passess all leetcode test cases as of Oct 7 2019
Runtime: 324 ms, faster than 35.37% of Python online submissions for Find Median from Data Stream.
Memory Usage: 23.6 MB, less than 100.00% of Python online submissions for Find Median from Data Stream.
"""
from heapq import *

class MedianFinder(object):
    def __init__(self):
        self.heaps = [], []

    def addNum(self, num):
        small, large = self.heaps
        heappush(small, -heappushpop(large, num))
        print(small); print(large)
        if len(large) < len(small):
            heappush(large, -heappop(small))
        print(small); print(large)
        
    def findMedian(self):
        small, large = self.heaps
        if len(large) > len(small):
            return float(large[0])
        return (large[0]-small[0])/2.0

mf = MedianFinder()
for i in range(1,11):
    mf.addNum(i)
print(mf.findMedian())