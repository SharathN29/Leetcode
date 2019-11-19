"""
Connecting Cities with Minimum Cost : https://leetcode.com/problems/connecting-cities-with-minimum-cost/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 13 2019
Runtime: 580 ms, faster than 91.60% of Python online submissions for Connecting Cities With Minimum Cost.
Memory Usage: 17.1 MB, less than 100.00% of Python online submissions for Connecting Cities With Minimum Cost.
"""
class Solution(object):
    def minimumCost(self, N, connections):
    	parents = [n for n in range(N)]
    	ranks = [1] * N

    	def find(u):
    		while u != parents[u]:
    			parents[u] = parents[parents[u]]
    			u = parents[u]
    		return u

    	def union(u,v):
    		rootU, rootV = find(u), find(v)
    		if rootU == rootV: return False
    		if ranks[rootV] > ranks[rootU]:
    			rootU, rootV = rootV, rootU
    		parents[rootV] = rootU
    		ranks[rootU] += ranks[rootV]
    		return True

    	connections.sort(key = lambda x: x[2])
    	ans = 0
    	for u, v, val in connections:
    		if union(u-1, v-1): ans += val
    	groups = len({find(x) for x in parents})
    	return ans if groups == 1 else -1

minC = Solution()
N, connections= 3, [[1,2,5],[1,3,6],[2,3,1]]
print(minC.minimumCost(N, connections))