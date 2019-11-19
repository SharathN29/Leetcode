"""
Two Sum III - Data structure design : https://leetcode.com/problems/two-sum-iii-data-structure-design/
Author : Sharath Nagendra

Passes all leetcode test cases as on Oct 4, 2019
Runtime: 224 ms, faster than 89.92% of Python online submissions for Two Sum III - Data structure design.
Memory Usage: 18.5 MB, less than 50.00% of Python online submissions for Two Sum III - Data structure design.
"""
class TwoSum:
    def __init__(self):
        self.sumDict = {}

    def add(self, number):
        if number in self.sumDict:
            self.sumDict[number] += 1
        else: self.sumDict[number] = 1
    
    def find(self, value):
        sumDict = self.sumDict
        for num in sumDict:
            if value - num in sumDict and (value - num != num or sumDict[num] > 1):
                return True
        return False