"""
Most Common Word : https://leetcode.com/problems/most-common-word/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 7 2019
Runtime: 24 ms, faster than 60.95% of Python online submissions for Most Common Word.
Memory Usage: 12 MB, less than 10.71% of Python online submissions for Most Common Word.
"""
import collections
import re

class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        ban = set(banned)
        words = re.findall(r'\w+', paragraph.lower())
        return collections.Counter(w for w in words if w not in ban).most_common(1)[0][0]

paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
mc = Solution()
print(mc.mostCommonWord(paragraph, banned))