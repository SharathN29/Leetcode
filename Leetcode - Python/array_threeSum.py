"""
Three Sum : https://leetcode.com/problems/3sum/
Author : Sharath Nagendra

Passes all leetcode test cases as on Oct 4, 2019
Runtime: 552 ms, faster than 90.28% of Python online submissions for 3Sum.
Memory Usage: 15 MB, less than 32.69% of Python online submissions for 3Sum.
"""
def threeSum(nums):
    res = []
    nums.sort()
    length = len(nums)
    for i in range(length-2):
        if nums[i] > 0: break
        if i > 0 and nums[i] == nums[i-1]: continue 

        l, r = i+1, length-1
        while l < r:
            total = nums[l] + nums[i] + nums[r]
            if total < 0:
                l += 1
            elif total > 0:
                r -= 1
            else:
                res.append(nums[i], nums[l], nums[r])
                while l < r and nums[l] == nums[l+1]:
                    l += 1
                while l < r and nums[r] == nums[r-1]:
                    r -= 1
                l += 1
                r -= 1
    return res

nums = [-1, 0, 1, 2, -1, -4]
print(threeSum(nums))