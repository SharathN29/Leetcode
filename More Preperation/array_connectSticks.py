"""
Minimum Cost to Connect Sticks : https://leetcode.com/problems/minimum-cost-to-connect-sticks/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 13 2019
Runtime: 792 ms, faster than 89.45% of Python online submissions for Minimum Cost to Connect Sticks.
Memory Usage: 12.7 MB, less than 100.00% of Python online submissions for Minimum Cost to Connect Sticks.
"""
import heapq

class Solution(object):
    def connectSticks(self, sticks):
    	heapq.heapify(sticks)
    	res = 0
    	while len(sticks) > 1:
    		x, y = heapq.heappop(sticks), heapq.heappop(sticks)
    		res += x+y
    		heapq.heappush(sticks, x+y)
    	return res

stick = Solution()
sticks = [1,8,3,5]
print(stick.connectSticks(sticks))