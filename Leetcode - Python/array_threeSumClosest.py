"""
3Sum Closest : https://leetcode.com/problems/3sum-closest/
Author : Sharath Nagendra 

Passes all leetcode test case as on Oct 4, 2019. 
Runtime: 100 ms, faster than 62.31% of Python online submissions for 3Sum Closest.
Memory Usage: 11.7 MB, less than 74.19% of Python online submissions for 3Sum Closest.
"""
def threeSumClosest(nums, target):
    nums.sort()
    res = sum(nums[:3])
    for i in range(len(nums)-2):
        j, k = i+1, len(nums)-1
        while j < k:
            res1 = nums[i] + nums[j] + nums[k]
            if res1 == target:
                return res1 
            
            if abs(res1-target) < abs(res - target):
                res = res1

            if res1 < target:
                j += 1
            elif res1 > target:
                k -= 1
    return res

nums, target = [-1, 2, 1, -4], 4
print(threeSumClosest(nums, target))