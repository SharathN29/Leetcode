"""
Surrounded Regions : https://leetcode.com/problems/surrounded-regions/
Author : Sharath Nagendra

Passes all leetcode test cases as on Oct 5 2019
Runtime: 140 ms, faster than 37.82% of Python online submissions for Surrounded Regions.
Memory Usage: 16.9 MB, less than 47.62% of Python online submissions for Surrounded Regions.
"""
import collections

def solve(board):
    queue = collections.deque([])
    for i in range(len(board)):
        for j in range(len(board[0])):
            if (i in [0, len(board)-1] or j in [0, len(board[0])-1]) and board[i][j] == "0":
                queue.append((i,j))
    
    while queue:
        r, c = queue.popleft()
        if 0<=r<len(board) and 0<=c<len(board[0]) and board[r][c] == "0":
            board[r][c] = "D"
            queue.append((r-1,c)); queue.append((r+1,c))
            queue.append((r,c-1)); queue.append((r,c+1))
    
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == "0":
                board[i][j] = "X"
            elif board[i][j] == "D":
                board[i][j] = "0"

board = [["X","X","X","X"],["X","0","0","X"],["X","X","0","X"],["X","0","X","X"]]
solve(board)
print(board)

