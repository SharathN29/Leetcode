from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        arrayElements = {}
        for i in range(0, len(nums)):
            if target - nums[i] in  arrayElements.keys():
                return [arrayElements[target - nums[i]], i]
            else:
                arrayElements[nums[i]] = i
        return [-1, -1] 