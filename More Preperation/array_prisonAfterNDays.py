"""
Prison Cells After N Days : https://leetcode.com/problems/prison-cells-after-n-days/
Author : Sharath Nagendra 

Passes all leetcode test cases as of Oct 12 2019
Runtime: 20 ms, faster than 92.63% of Python online submissions for Prison Cells After N Days.
Memory Usage: 11.8 MB, less than 28.57% of Python online submissions for Prison Cells After N Days.
"""
class Solution(object):
    def prisonAfterNDays(self, cells, N):
        N -= int(max(N - 1, 0) / 14 * 14)
        for i in range(N):
            cells = [0] + [cells[i - 1] ^ cells[i + 1] ^ 1 for i in range(1, 7)] + [0]
        return cells

prison = Solution()
cells = [0,1,1,1,1,1,1,1]
N = 1289238
print(prison.prisonAfterNDays(cells, N))
            