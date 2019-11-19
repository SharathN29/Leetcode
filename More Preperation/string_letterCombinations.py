"""
Letter Combinations of a Phone Number : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 9 2019
Runtime: 12 ms, faster than 93.86% of Python online submissions for Letter Combinations of a Phone Number.
Memory Usage: 11.9 MB, less than 16.67% of Python online submissions for Letter Combinations of a Phone Number.
"""
class Solution(object):
    def letterCombinations(self, digits):
        if not digits:
            return []
        dic = {"2":"abc", "3":"def", "4":"ghi", "5":"jkl", "6":"mno", "7":"pqrs", "8":"tuv", "9":"wxyz"}
        res = []
        self.dfs(digits, dic, 0, "", res)
        return res

    def dfs(self, digits, dic, index, path, res):
        if len(path) == len(digits):
            res.append(path)
            return 
        for i in range(index, len(digits)):
            for j in dic[digits[i]]:
                self.dfs(digits, dic, i+1, path+j, res)

lc = Solution()
print(lc.letterCombinations("32"))