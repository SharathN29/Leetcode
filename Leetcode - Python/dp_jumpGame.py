"""
Jump Game : https://leetcode.com/problems/jump-game/
Author : Sharath Nagendra 

Passes all leetcode test cases as of Oct 9 2019
Runtime: 72 ms, faster than 68.09% of Python online submissions for Jump Game.
Memory Usage: 13.5 MB, less than 11.43% of Python online submissions for Jump Game.
"""
class Solution(object):
    def canJump(self, nums):
        if len(nums) < 2:
            return True
        dp = [0] * len(nums)
        dp[0] = nums[0]
        for i in range(1, len(nums)):
            if dp[i-1] < i:
                return False
            dp[i] = max(dp[i-1], i+nums[i])
        print(dp)
        return dp[-1] >= len(nums)-1

jump = Solution()
nums = [2,3,1,1,4]
print(jump.canJump(nums))
