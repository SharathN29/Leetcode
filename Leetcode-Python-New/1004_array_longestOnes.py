# https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left = right = maxlen = zeros = 0
        
        while right < len(nums):
            if nums[right] == 0:
                zeros += 1
                
            while zeros == k + 1:
                if nums[left] == 0:
                    zeros -= 1
                left += 1
                
            maxlen = max(maxlen , right - left + 1)
            right += 1
        
        return maxlen