# https://leetcode.com/problems/max-consecutive-ones-ii/

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        left = maxlen = zeros = 0
        
        for right in range(len(nums)):
            if nums[right] == 0:
                zeros += 1
                
            while zeros == 2:
                if nums[left] == 0:
                    zeros -= 1
                left += 1
            
            maxlen = max(maxlen, right - left + 1)
            
        return maxlen