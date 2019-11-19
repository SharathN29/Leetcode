"""
Number of Islands : https://leetcode.com/problems/number-of-islands/
Author : Sharath Nagendra

Passes all leetcode test cases as on Oct 4, 2019
Runtime: 132 ms, faster than 60.33% of Python online submissions for Number of Islands.
Memory Usage: 18.7 MB, less than 100.00% of Python online submissions for Number of Islands.
"""
def dfs(grid, r, c):
    if r < 0 or c < 0 or r > len(grid) or c > len(grid[0]) or grid[r][c] != '1':
        return 
    grid[r][c] = '#'
    dfs(grid, r+1, c)
    dfs(grid, r-1, c)
    dfs(grid, r, c+1)
    dfs(grid, r, c-1)

def numIslands(grid):
    if not grid:
        return 0
    count = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == '1':
                count += 1
                dfs(grid, i, j)
    return count 