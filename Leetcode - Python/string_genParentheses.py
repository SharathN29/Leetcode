"""
Generate Parentheses : https://leetcode.com/problems/generate-parentheses/
Author : Sharath Nagendra 

Passes all leetcode test cases as of Oct 10 2019
Runtime: 20 ms, faster than 78.94% of Python online submissions for Generate Parentheses.
Memory Usage: 12.1 MB, less than 29.41% of Python online submissions for Generate Parentheses.
"""
class Solution(object):
    def generateParenthesis(self, n):
        res = []
        self.generate(n, n, "", res)
        return res

    def generate(self, left, right, path, res):
        if left > right or left < 0 or right < 0:
            return 
        if left == 0 and right == 0:
            res.append(path)
            return
        self.generate(left-1, right, path+"(", res)
        self.generate(left, right-1, path+")", res)

gp = Solution()
print(gp.generateParenthesis(3))