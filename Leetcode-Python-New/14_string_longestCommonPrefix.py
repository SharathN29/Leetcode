# https://leetcode.com/problems/longest-common-prefix/

from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if strs is None or len(strs) == 0: 
            return ""
        
        longest_prefix = strs[0]
        for i in range(1, len(strs)):
            while not strs[i].startswith(longest_prefix):
                longest_prefix = longest_prefix[0 : len(longest_prefix) - 1]
        
        return longest_prefix

def main():
    sol = Solution()
    strs = ["flower", "fly", "flying"]
    print(sol.longestCommonPrefix(strs))

if __name__ == "__main__":
    main()

