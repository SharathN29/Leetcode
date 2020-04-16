"""
Walls and Gates : https://leetcode.com/problems/walls-and-gates/
Author : Sharath Nagendra

Passes all leetcode test cases as on Oct 5 2019
Runtime: 468 ms, faster than 10.62% of Python online submissions for Walls and Gates.
Memory Usage: 14.8 MB, less than 66.67% of Python online submissions for Walls and Gates.
"""
import collections

def wallsAndGates(rooms):
    if not rooms: return 
    r,c = len(rooms), len(rooms[0])
    for i in range(r):
        for j in range(c):
            if rooms[i][j] == 0:
                queue = collections.deque([])
                queue.append((i-1,j,1)); queue.append((i+1,j,1))
                queue.append((i,j-1,1)); queue.append((i,j+1,1))
                visited = set()
                while queue:
                    x,y,val = queue.popleft()
                    if x<0 or x>=r or y<0 or y>=c or rooms[x][y] in [0,-1] or (x,y) in visited:
                        continue
                    visited.add((x,y))
                    rooms[x][y] = min(rooms[x][y], val)
                    queue.append((x+1,y,val+1)); queue.append((x-1,y,val+1))
                    queue.append((x,y+1,val+1)); queue.append((x,y-1,val+1))

rooms = [[1234,-1,0,1234],[1234,1234,1234,-1],[1234,-1,1234,-1],[0,-1,1234,1234]]
wallsAndGates(rooms)
print(rooms)