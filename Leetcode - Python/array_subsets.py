"""
Subsets : https://leetcode.com/problems/subsets/
Author: Sharath Nagendra 

Passes all leetcode testcases as on Sept 17 2019
Runtime: 20 ms, faster than 69.94% of Python online submissions for Subsets.
Memory Usage: 11.8 MB, less than 100.00% of Python online submissions for Subsets.
"""
def subsets(nums):
	res = []
	dfs(nums, 0, [], res)
	return res

def dfs(nums, index, path, res):
	res.append(path)
	for i in range(index, len(nums)):
		dfs(nums, i+1, path+[nums[i]], res)

nums = [1, 2, 3]
print(subsets(nums)) 