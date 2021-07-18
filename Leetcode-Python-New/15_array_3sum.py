# https://leetcode.com/problems/3sum/

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if nums is None or len(nums) == 0:
            return []
        triplets = []
        nums.sort()
        
        for i in range(len(nums) - 2):
            if i == 0 or (i > 0 and nums[i] != nums[i - 1]):
                target = -nums[i]
                left, right = i + 1, len(nums) - 1
                
                while left < right:
                    curr_sum = nums[left] + nums[right]
                    if curr_sum == target:
                        curr_triplets = [nums[i], nums[left], nums[right]]
                        triplets.append(curr_triplets)
                        
                        while left < right and nums[left] == nums[left + 1]: left += 1
                        while left < right and nums[right] == nums[right - 1]: right -= 1
                        left += 1
                        right -=1
                    elif curr_sum > target: 
                        right -= 1
                    else:
                        left += 1
        return triplets