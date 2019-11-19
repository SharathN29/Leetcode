"""
Group Anagrams : https://leetcode.com/problems/group-anagrams/
Author : Sharath Nagendra 

Passes all leetcode test cases as of Oct 16 2019
Runtime: 80 ms, faster than 89.61% of Python online submissions for Group Anagrams.
Memory Usage: 16.2 MB, less than 41.67% of Python online submissions for Group Anagrams.
"""
import collections

class Solution(object):
    def groupAnagrams(self, strs):
        ans = collections.defaultdict(list)
        for s in strs:
            ans[tuple(sorted(s))].append(s)
        return ans.values()

strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
ga = Solution()
print(ga.groupAnagrams(strs))