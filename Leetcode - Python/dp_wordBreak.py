"""
Word Break : https://leetcode.com/problems/word-break/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 9 2019
Runtime: 28 ms, faster than 61.27% of Python online submissions for Word Break.
Memory Usage: 11.8 MB, less than 74.47% of Python online submissions for Word Break.
"""
class Solution(object):
    def wordBreak(self, s, wordDict):
        dp = [False] * (len(s)+1)
        dp[0] = True
        for i in range(len(s)):
            for j in range(i, len(s)):
                if dp[i] and s[i:j+1] in wordDict:
                    dp[j+1] = True
        return dp[-1]
    
s = "catsandog" 
wordDict = ["cats", "dog", "sand", "and", "cat"]
wb = Solution()
print(wb.wordBreak(s, wordDict)) 
