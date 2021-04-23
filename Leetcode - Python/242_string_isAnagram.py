# https://leetcode.com/problems/valid-anagram/

import collections


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        map = collections.defaultdict(int)
        for c in s:
            map[c] += 1
        for c in t:
            map[c] -= 1
        return all(x == 0 for x in map.values())
