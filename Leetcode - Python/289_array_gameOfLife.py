# https://leetcode.com/problems/game-of-life/

class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                if board[i][j] == 0 or board[i][j] == 2:
                    if self.numLiveCells(board, i, j) == 3:
                        board[i][j] = 2

                else:
                    if self.numLiveCells(board, i, j) < 2 or self.numLiveCells(board, i, j) > 3:
                        board[i][j] = 3

        for i in range(m):
            for j in range(n):
                if board[i][j] == 2:
                    board[i][j] = 1
                if board[i][j] == 3:
                    board[i][j] = 0

    def numLiveCells(self, board: List[List[int]], i: int, j: int) -> int:
        m, n = len(board), len(board[0])
        count = 0

        if i-1 >= 0 and j-1 >= 0:
            count += board[i-1][j-1] % 2
        if i-1 >= 0:
            count += board[i-1][j] % 2
        if i-1 >= 0 and j+1 < n:
            count += board[i-1][j+1] % 2
        if j-1 >= 0:
            count += board[i][j-1] % 2
        if j+1 < n:
            count += board[i][j+1] % 2
        if i+1 < m and j-1 >= 0:
            count += board[i+1][j-1] % 2
        if i+1 < m:
            count += board[i+1][j] % 2
        if i+1 < m and j+1 < n:
            count += board[i+1][j+1] % 2

        return count
