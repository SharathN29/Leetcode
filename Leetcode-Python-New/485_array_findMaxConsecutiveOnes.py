# https://leetcode.com/problems/max-consecutive-ones/

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxcount = one = 0
        for n in nums:
            if n == 1:
                one += 1
            else:
                maxcount = max(maxcount, one)
                one = 0
        return max(maxcount, one)