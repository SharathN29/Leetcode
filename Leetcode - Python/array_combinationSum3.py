"""
Combination Sum 3 : https://leetcode.com/problems/combination-sum-iii/
Author : Sharath Nagendra

Pases all leetcode test cases as on Sept 17 2019
Runtime: 20 ms, faster than 55.06% of Python online submissions for Combination Sum III.
Memory Usage: 11.7 MB, less than 50.00% of Python online submissions for Combination Sum III.
"""
def combinationSum(k, n):
	res = []
	dfs(range(1,10), k, n, 0, [], res)
	return res

def dfs(nums, k, n, index, path, res):
	if k < 0 or n < 0:
		return 
	if k == 0 and n == 0:
		res.append(path)
	for i in range(index, len(nums)):
		dfs(nums, k-1, n-nums[i], i+1, path+[nums[i]], res)

k, n = 3, 7
print(combinationSum(k, n))