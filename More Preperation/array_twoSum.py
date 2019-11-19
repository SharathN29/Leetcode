"""
Two Sum : https://leetcode.com/problems/two-sum/
Author : Sharath Nagendra 

Passes all leetcode test cases as on Oct 4, 2019. 
Runtime: 36 ms, faster than 74.87% of Python online submissions for Two Sum.
Memory Usage: 13.1 MB, less than 32.88% of Python online submissions for Two Sum.
"""
def twoSum(nums, target):
    if(len(nums)) <= 1:
        return False
    resDict = {}
    for i in range(len(nums)):
        if nums[i] in resDict:
            return [resDict[nums[i]], i]
        else: resDict[target-nums[i]] = i

nums, target = [2,7,11,15], 9
print(twoSum(nums, target))