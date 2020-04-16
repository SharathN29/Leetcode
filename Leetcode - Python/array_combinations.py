"""
Combinations : https://leetcode.com/problems/combinations/
Author : Sharath Nagendra

Passes all leetcode test cases as on Sept 17 2019

"""
def combine(n, k):
	res = []
	dfs(range(1,n+1), k, 0, [], res)
	return res

def dfs(nums, k, index, path, res):
	if k == 0:
		res.append(path)
		return 
	for i in range(index, len(nums)):
		dfs(nums, k-1, i+1, path+[nums[i]], res)

n, k = 4, 2
print(combine(n, k))