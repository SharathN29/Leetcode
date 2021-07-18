# https://leetcode.com/problems/subarray-product-less-than-k/

class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1: 
            return 0
        start, window_product, count = 0, 1, 0
        for end in range(len(nums)):
            window_product *= nums[end]
            while window_product >= k:
                window_product /= nums[start]
                start += 1
            count += end - start + 1
        return count