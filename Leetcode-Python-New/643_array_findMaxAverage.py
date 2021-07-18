# https://leetcode.com/problems/maximum-average-subarray-i/

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        max_avg = -float('inf')
        i, windowSum = 0, 0.0
        
        for j in range(len(nums)):
            windowSum += nums[j]
            if j >= k - 1:
                avg = windowSum / k
                max_avg = max(max_avg, avg)
                windowSum -= nums[i]
                i += 1
                
        return max_avg