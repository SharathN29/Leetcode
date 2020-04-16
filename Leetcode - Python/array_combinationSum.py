"""
Combination Sum : https://leetcode.com/problems/combination-sum/
Author : Sharath Nagendra

Passes all leetcode test cases as on Sept 17 2019
Runtime: 100 ms, faster than 36.54% of Python online submissions for Combination Sum.
Memory Usage: 11.5 MB, less than 100.00% of Python online submissions for Combination Sum.
"""
def combinationSum(candidates, target):
	res = []
	candidates.sort()
	dfs(candidates, target, 0, [], res)
	return res

def dfs(nums, target, index, path, res):
	if target < 0:
		return
	if target == 0:
		res.append(path)
		return
	for i in range(index, len(nums)):
		dfs(nums, target-nums[i], i, path+[nums[i]], res)

candidates, target = [2,3,6,7], 7
print(combinationSum(candidates, target))
