# https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        left, max_len = 0, 0
        char_count = {}
        
        for right in range(len(s)):
            right_char = s[right]
            if right_char not in char_count: 
                char_count[right_char] = 0
            char_count[right_char] += 1
            
            while len(char_count) > k:
                left_char = s[left]
                char_count[left_char] -= 1
                left += 1
                if char_count[left_char] == 0:
                    del char_count[left_char]
            
            max_len = max(max_len, right - left + 1)
        
        return max_len