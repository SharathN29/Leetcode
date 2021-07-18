# https://leetcode.com/problems/3sum-closest/

from typing import List

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        min_diff = float('inf')
        nums.sort()
        
        for i in range(len(nums)):
            left, right = i + 1, len(nums) - 1
            while left < right:
                sum = nums[i] + nums[left] + nums[right]
                if abs(target - sum) < abs(min_diff):
                    min_diff = target - sum
                if sum < target: left += 1
                else: right -= 1
            if min_diff == 0: break    
            
        return target - min_diff