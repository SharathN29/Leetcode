# https://leetcode.com/problems/brick-wall/

import sys
import collections


class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        res = -sys.maxsize - 1
        m = collections.defaultdict(int)

        for row in wall:
            width = 0
            for b in row[: -1]:
                width += b
                m[width] += 1

        return len(wall) - max(m.values(), default=0)
