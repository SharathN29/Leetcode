"""
The Maze : https://leetcode.com/problems/the-maze/
Author : Sharath Nagendra

Passes all leetcode test cases as on Oct 5 2019
Runtime: 248 ms, faster than 91.19% of Python online submissions for The Maze.
Memory Usage: 13.4 MB, less than 100.00% of Python online submissions for The Maze.
"""
def hasPathBFS(maze, start, destination):
    Q = [start]
    m = len(maze)
    n = len(maze[0])
    dirs = ((0,1),(0,-1),(1,0),(-1,0))

    while Q:
        i, j = Q.pop()
        maze[i][j] = 2

        if i == destination[0] and j == destination[1]:
            return True 
        
        for x,y in dirs:
            row, col = i+x, j+y
            while 0<=row<m and 0<=col<n and maze[row][col] != 1:
                row += x
                col += y
            row -= x
            col -= y
            if maze[row][col] == 0:
                Q.append([row,col])
    return False

def hasPathDFS(maze, start, destination):
    m, n, stopped = len(maze), len(maze[0]), set()
    def dfs(x, y):
        if (x, y) in stopped: 
            return False
        stopped.add((x, y))
        if [x, y] == destination:
            return True
        for i, j in (-1, 0) , (1, 0), (0, -1), (0, 1):
            newX, newY = x, y
            while 0 <= newX + i < m and 0 <= newY + j < n and maze[newX + i][newY + j] != 1:
                newX += i
                newY += j
            if dfs(newX, newY):
                return True
        return False
    return dfs(*start)

maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]
start, destination = (0,4), (4,4)
print(hasPathBFS(maze, start, destination))
maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]
start, destination = (0,4), (4,4)
print(hasPathDFS(maze, start, destination))