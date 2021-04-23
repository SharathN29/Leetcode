# https://leetcode.com/problems/beautiful-arrangement/

from typing import List


class Solution:
    def __init__(self):
        self.count = 0

    def countArrangement(self, n: int) -> int:
        visited = [False for _ in range(n+1)]
        self.calculatePerm(n, 1, visited)
        return self.count

    def calculatePerm(self, n: int, pos: int, visited: List[bool]) -> None:
        if pos > n:
            self.count += 1
        for i in range(1, n + 1):
            if visited[i] is False and (pos % i == 0 or i % pos == 0):
                visited[i] = True
                self.calculatePerm(n, pos + 1, visited)
                visited[i] = False
