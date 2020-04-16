"""
First Missing Positive : https://leetcode.com/problems/first-missing-positive/
Author : Sharath Nagendra 

Passes all leetcode test cases as of Oct 10 2019
Runtime: 24 ms, faster than 52.72% of Python online submissions for First Missing Positive.
Memory Usage: 11.8 MB, less than 32.35% of Python online submissions for First Missing Positive.
"""
class Solution(object):
    def firstMissingPositive(self, nums):
        n = len(nums)
        if 1 not in nums:
            return 1
        if n == 1:
            return 2

        for i in range(n):
            if nums[i] <= 0 or nums[i] > n:
                nums[i] = 1
        
        for i in range(n):
            a = abs(nums[i])
            if a == n:
                nums[0] = -abs(nums[0])
            else: nums[a] = -abs(nums[a])

        for i in range(1,n):
            if nums[i] > 0:
                return i
        
        if nums[0] > 0:
            return n
        
        return n+1

fmp = Solution()
print(fmp.firstMissingPositive([3,4,-1,1]))