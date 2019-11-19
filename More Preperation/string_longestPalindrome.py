"""
Longest Palindromic Substring : https://leetcode.com/problems/longest-palindromic-substring/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 15 2019
Runtime: 796 ms, faster than 85.97% of Python online submissions for Longest Palindromic Substring.
Memory Usage: 11.9 MB, less than 58.90% of Python online submissions for Longest Palindromic Substring.
"""
class Solution(object):
    def longestPalindrome(self, s):
    	res = ""
    	for i in range(len(s)):
    		temp = self.helper(s, i, i)
    		if len(temp) > len(res):
    			res = temp
    		temp = self.helper(s, i, i+1)
    		if len(temp) > len(res):
    			res = temp
    	return res

    def helper(self, s, left, right):
    	while left >= 0 and right < len(s) and s[left] == s[right]:
    		left -= 1; right += 1
    	return s[left+1:right]

lp = Solution()
s = "babad"
print(lp.longestPalindrome(s))