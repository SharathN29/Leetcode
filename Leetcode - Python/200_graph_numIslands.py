# https://leetcode.com/problems/number-of-islands/

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid or not grid[0]:
            return 0

        m, n = len(grid), len(grid[0])
        numIsland = 0

        for r in range(m):
            for c in range(n):
                if grid[r][c] == '1':
                    numIsland += 1
                    self.dfs(grid, r, c)
        return numIsland

    def dfs(self, grid: List[List[str]], r: int, c: int) -> None:
        grid[r][c] = '0'
        dirs = [(-1,0),(1,0),(0,-1),(0,1)]
        for d in dirs:
            nr, nc = r + d[0], c + d[1]
            if self.isValid(grid, nr, nc) and grid[nr][nc] == '1':
                self.dfs(grid, nr, nc)

    def isValid(self, grid: List[List[str]], r: int, c: int) -> bool:
        m, n = len(grid), len(grid[0])
        if r < 0 or r >= m or c < 0 or c >= n:
            return False
        return True