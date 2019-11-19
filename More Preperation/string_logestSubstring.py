"""
Longest Substring Without Repeating Characters : https://leetcode.com/problems/longest-substring-without-repeating-characters/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 17 2019
"""
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        dic, start, res = {}, 0, 0
        for i, ch in enumerate(s):
            if ch in dic:
                res = max(res, i-start)
                start = max(start, dic[ch]+1)
            dic[ch] = i
        return max(res, len(s)-start)

substr = Solution()
s = "abcabcbb"
print(substr.lengthOfLongestSubstring(s))