"""
Pancake Sorting : https://leetcode.com/problems/pancake-sorting/
Author: Sharath Nagendra

Passes all leetcode testcases as on Sept 17 2019
Runtime: 24 ms, faster than 91.16% of Python online submissions for Pancake Sorting.
Memory Usage: 11.8 MB, less than 14.29% of Python online submissions for Pancake Sorting.
"""
def pancakeSort(A):
	res = []
	for x in range(len(A), 1, -1):
		i = A.index(x)
		res.extend([i+1, x])
		A = A[:i:-1] + A[:i]
	return res

A = [1,2,3]
print(pancakeSort(A))