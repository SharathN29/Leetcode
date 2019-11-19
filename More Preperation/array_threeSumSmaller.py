"""
3Sum Smaller : https://leetcode.com/problems/3sum-smaller/
Author : Sharath Nagendra 

Passes all leetcode test cases as on Oct 4 2019.
Runtime: 100 ms, faster than 75.49% of Python online submissions for 3Sum Smaller.
Memory Usage: 11.8 MB, less than 20.00% of Python online submissions for 3Sum Smaller.
"""
def threeSumSmaller(nums, target):
    result = 0
    nums.sort()
    for i in range(len(nums)-2):
        l, r = i+1, len(nums)-1
        while l < r:
            if nums[l] + nums[r] + nums[i] < target:
                result += r-l
                l += 1
            else: r -= 1
    return result

nums, target = [-2,0,1,3], 2
print(threeSumSmaller(nums, target))