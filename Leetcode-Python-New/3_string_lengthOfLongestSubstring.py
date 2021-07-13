# https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i, maxlen = 0, 0
        charToIndex = {}
        
        for j in range(len(s)):
            if s[j] in charToIndex:
                i = max(i, charToIndex[s[j]] + 1)
                
            charToIndex[s[j]] = j
            maxlen = max(maxlen, j - i + 1)
        
        return maxlen
            