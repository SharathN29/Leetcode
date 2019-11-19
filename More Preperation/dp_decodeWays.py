"""
Decode Ways : https://leetcode.com/problems/decode-ways/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 10 2019
Runtime: 16 ms, faster than 91.74% of Python online submissions for Decode Ways.
Memory Usage: 11.8 MB, less than 47.83% of Python online submissions for Decode Ways.
"""
class Solution(object):
    def numDecodings(self, s):
        if not s:
            return 0
        dp = [0] * (len(s)+ 1)
        dp[0] = 1
        for i in range(1, len(s)+1):
            if s[i-1] != '0':
                dp[i] += dp[i-1]
            if i != 1 and s[i-2:i] < "27" and s[i-2:i] > "09":
                dp[i] += dp[i-2]
        return dp[-1]

nd = Solution()
print(nd.numDecodings("226"))