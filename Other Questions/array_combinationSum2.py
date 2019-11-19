"""
Combination Sum II : https://leetcode.com/problems/combination-sum-ii/
Author : Sharath Nagendra

Passes all leetcode test cases as on Sept 17 2019
Runtime: 80 ms, faster than 49.46% of Python online submissions for Combination Sum II.
Memory Usage: 11.9 MB, less than 25.81% of Python online submissions for Combination Sum II.
"""
def combinationSum(candidates, target):
	res = []
	candidates.sort()
	dfs(candidates, target, 0, [], res)
	return res

def dfs(candidates, target, index, path, res):
	if target < 0:
		return
	if target == 0:
		res.append(path)
		return 
	for i in range(index, len(candidates)):
		if i > index and candidates[i] == candidates[i-1]:
			continue
		dfs(candidates, target-candidates[i], i+1, path+[candidates[i]], res)

candidates, target = [10,1,2,7,6,1,5], 8
print(combinationSum(candidates, target))
