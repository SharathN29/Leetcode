"""
4Sum : https://leetcode.com/problems/4sum/
Author : Sharath Nagendra

Passes all leetcode test cases as on Oct 4 2019.
Runtime: 608 ms, faster than 58.64% of Python online submissions for 4Sum.
Memory Usage: 11.7 MB, less than 90.91% of Python online submissions for 4Sum.
"""
def threeSum(nums, target):
    res = []
    length = len(nums)
    for i in range(length-2):
        if i > 0 and nums[i] == nums[i-1]: continue 

        l, r, t = i+1, length-1, target-nums[i]
        while l < r:
            total = nums[l] +  nums[r]
            if total < t:
                l += 1
            elif total > t:
                r -= 1
            else:
                res.append([nums[i], nums[l], nums[r]])
                while l < r and nums[l] == nums[l+1]:
                    l += 1
                while l < r and nums[r] == nums[r-1]:
                    r -= 1
                l += 1
                r -= 1
    return res

def fourSum(nums, target):
    result = []
    nums.sort()
    for i in range(len(nums)-3):
        if i == 0 or nums[i] != nums[i-1]:
            threeSumRes = threeSum(nums[i+1:], target-nums[i])
            for item in threeSumRes:
                result.append([nums[i]]+item)
    return result

nums, target = [1, 0, -1, 0, -2, 2], 0
print(fourSum(nums, target))