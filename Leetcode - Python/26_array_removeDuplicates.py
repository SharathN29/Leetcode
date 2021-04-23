# https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        size = len(nums)
        if size == 0:
            return 0
        i = 0

        for j in range(1, size):
            if nums[i] != nums[j]:
                i += 1
                nums[i] = nums[j]

        return i + 1
