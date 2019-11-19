"""
Minimum Path Sum : https://leetcode.com/problems/minimum-path-sum/
Author : Sharath Nagendra

Passes all leetcode test cases as of oct 10 2019
Runtime: 84 ms, faster than 51.26% of Python online submissions for Minimum Path Sum.
Memory Usage: 13.2 MB, less than 17.65% of Python online submissions for Minimum Path Sum.
"""
class Solution(object):
    def minPathSum(self, grid):
        if not grid:
            return 
        r, c = len(grid), len(grid[0])
        dp = [[0 for _ in range(c)] for _ in range(r)]
        dp[0][0] = grid[0][0]
        for i in range(1, r):
            dp[i][0] = dp[i-1][0] + grid[i][0]
        for i in range(1, c):
            dp[0][i] = dp[0][i-1] + grid[0][i]
        for i in range(1, len(grid)):
            for j in range(1, len(grid[0])):
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
        return dp[-1][-1]

mp = Solution()
grid = [
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
print(mp.minPathSum(grid))