"""
Subsets 2 : https://leetcode.com/problems/subsets-ii/
Author : Sharath Nagendra

Passes all leetcode test cases as on Sept 17 2019
Runtime: 16 ms, faster than 97.29% of Python online submissions for Subsets II.
Memory Usage: 11.8 MB, less than 84.62% of Python online submissions for Subsets II.
"""
def subsetsWithDup(nums):
	res = []
	nums.sort()
	dfs(nums, 0, [], res)
	return res

def dfs(nums, index, path, res):
	res.append(path)
	for i in range(index, len(nums)):
		if i > index and nums[i] == nums[i-1]:
			continue
		dfs(nums, i+1, path+[nums[i]], res)

print(subsetsWithDup([1,2,2]))