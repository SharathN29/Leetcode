"""
Height Checker : https://leetcode.com/problems/height-checker/
Author : Sharath Nagendra

Passes all leetcode test cases as of Nov 2 2019
Runtime: 20 ms, faster than 82.50% of Python online submissions for Height Checker.
Memory Usage: 11.6 MB, less than 100.00% of Python online submissions for Height Checker.
"""
class Solution(object):
    def heightChecker(self, heights):
        res = 0
        height = sorted(heights)
        for i in range(len(height)):
            if heights[i] != height[i]:
                res += 1
        return res

hc = Solution()
heights = [1,2,1,2,1,1,1,2,1]
print(hc.heightChecker(heights))