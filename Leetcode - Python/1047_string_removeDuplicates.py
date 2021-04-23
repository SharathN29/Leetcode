# https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution:
    def removeDuplicates(self, S: str) -> str:
        res = []
        for c in S:
            if res and res[-1] == c:
                res.pop()
            else:
                res.append(c)

        return ''.join(res)

s = Solution()
res = s.removeDuplicates("abbaca")
print(res)
