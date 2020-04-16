"""
Game of Life : https://leetcode.com/problems/game-of-life/
Author : Sharath Nagendra 

Passes all leetcode test cases as of Oct 6 2019
Runtime: 8 ms, faster than 99.45% of Python online submissions for Game of Life.
Memory Usage: 11.7 MB, less than 56.25% of Python online submissions for Game of Life.
"""
def gameOfLife(board):
    neighbors = [(-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1)]
    rows, cols = len(board), len(board[0])

    for row in range(rows):
        for col in range(cols):
            liveNeighbors = 0
            for neighbor in neighbors:
                r, c = row+neighbor[0], col+neighbor[1]
                if r>=0 and r<rows and c>=0 and c<cols and abs(board[r][c]) == 1:
                    liveNeighbors += 1

            if board[row][col] == 1 and (liveNeighbors<2 or liveNeighbors>3):
                board[row][col] = -1

            if board[row][col] == 0 and liveNeighbors == 3:
                board[row][col] = 2

    for row in range(rows):
        for col in range(cols):
            if board[row][col] > 0:
                board[row][col] = 1
            else: board[row][col] = 0



board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
gameOfLife(board)
print(board)