"""
Jump Game II : https://leetcode.com/problems/jump-game-ii/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 10 2019
Runtime: 76 ms, faster than 77.53% of Python online submissions for Jump Game II.
Memory Usage: 13.4 MB, less than 16.67% of Python online submissions for Jump Game II.
"""

class Solution(object):
    def jump(self, nums):
        jumps, End, Far = 0, 0, 0
        for i in range(0, len(nums)-1):
            Far = max(Far, i+nums[i])
            if i == End:
                jumps += 1
                End = Far
        return jumps

jump = Solution()
nums = [3,2,1,0,4]
print(jump.jump(nums))
             