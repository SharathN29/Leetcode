"""
Broken Calculator : https://leetcode.com/problems/broken-calculator/
Author : Sharath Nagendra 

Passes all leetcode test cases as of Oct 14 2019
Runtime: 16 ms, faster than 64.32% of Python online submissions for Broken Calculator.
Memory Usage: 11.5 MB, less than 100.00% of Python online submissions for Broken Calculator.
"""
class Solution(object):
    def brokenCalc(self, x, y):
    	res = 0
    	while y > x:
    		res += 1
    		if y % 2: y += 1
    		else: y /= 2
    	return res+x-y

calc = Solution()
print(calc.brokenCalc(3,10))