"""
K Closest Points to Origin : https://leetcode.com/problems/k-closest-points-to-origin/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 16 2019
Runtime: 584 ms, faster than 76.77% of Python online submissions for K Closest Points to Origin.
Memory Usage: 18.5 MB, less than 15.09% of Python online submissions for K Closest Points to Origin.
"""
import heapq

class Solution(object):
    def kClosest(self, points, K):
    	heap = []
    	for (x,y) in points:
    		dist = -(x*x + y*y)
    		if len(heapq) == K:
    			heapq.heappushpop(heap, (dist, x, y))
    		else: 
    			heapq.heappush(heap, (dis, x, y))
    	return [(x,y) for (dist,x,y)in heap]