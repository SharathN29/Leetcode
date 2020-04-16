"""
Minimum Window Substring : https://leetcode.com/problems/minimum-window-substring/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 29 2019
Runtime: 44 ms, faster than 99.98% of Python online submissions for Minimum Window Substring.
Memory Usage: 12.5 MB, less than 75.00% of Python online submissions for Minimum Window Substring.
"""
import collections

class Solution(object):
    def minWindow(self, s, t):
    	targetCountDict = collections.defaultdict(int)
    	for ch in t:
    		targetCountDict[ch] += 1
    	remainMissing = len(t)
    	startPos, endPos = 0, float('inf')
    	currentStart = 0

    	for currentEnd, ch in enumerate(s, 1):
    		if targetCountDict[ch] > 0:
    			remainMissing -= 1
    		targetCountDict[ch] -= 1

    		if remainMissing == 0:
    			while targetCountDict[s[currentStart]] < 0:
    				targetCountDict[s[currentStart]] += 1
    				currentStart += 1
    			if currentEnd - currentStart < endPos - startPos:
    				startPos, endPos = currentStart, currentEnd

    			targetCountDict[s[currentStart]] += 1
    			remainMissing += 1
    			currentStart += 1

    	return s[startPos:endPos] if endPos != float('inf') else ""

mw = Solution()
s, t = "ADOBECODEBANC", "ABC"
print(mw.minWindow(s, t))