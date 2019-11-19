"""
Capacity to ship packages within D days: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
Author: Sharath Nagendra 

Passes all the leetcode test cases as on Sept 17 2019
Runtime: 460 ms, faster than 68.03% of Python online submissions for Capacity To Ship Packages Within D Days.
Memory Usage: 14.1 MB, less than 77.78% of Python online submissions for Capacity To Ship Packages Within D Days.
"""
def shipWithinDays(weights, D):
	left, right = max(weights), sum(weights)
	while left < right:
		mid, need, cur = (left + right) / 2, 1, 0
		for w in weights:
			if cur + w > mid:
				need += 1
				cur = 0
			cur += w
		if need > D:
			left = mid + 1
		else:
			right = mid
	return left

weights = [3,2,2,4,1,4]
D = 3
print(shipWithinDays(weights, D))