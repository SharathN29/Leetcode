# https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        start, min_length, window_sum = 0, len(nums) + 1, 0
        for end in range(len(nums)):
            window_sum += nums[end]
            while window_sum >= target:
                min_length = min(min_length, end - start + 1)
                window_sum -= nums[start]
                start += 1
        return min_length % (len(nums) + 1)
        