# https://leetcode.com/problems/walls-and-gates/

import collections

class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        if not rooms:
            return

        rows, cols = len(rooms), len(rooms[0])
        dirs = [(-1,0),(0,-1),(1,0),(0,1)]
        queue = collections.deque()
        for r in range(rows):
            for c in range(cols):
                if rooms[r][c] == 0:
                    queue.append((r,c))

        while queue:
            r, c = queue.popleft()
            distance = rooms[r][c] + 1
            for dx, dy in dirs:
                x, y = r + dx, c + dy
                if 0 <= x < rows and 0 <= y < cols and rooms[x][y] == 2147483647:
                    rooms[x][y] = distance
                    queue.append((x,y))