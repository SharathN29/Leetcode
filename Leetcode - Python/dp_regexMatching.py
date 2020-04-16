"""
Regular Expression Matching : https://leetcode.com/problems/regular-expression-matching/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 10 2019
Runtime: 44 ms, faster than 66.97% of Python online submissions for Regular Expression Matching.
Memory Usage: 11.6 MB, less than 97.87% of Python online submissions for Regular Expression Matching.
"""
class Solution(object):
    def isMatch(self, s, p):
        n, m = len(s), len(p)
        match = [[False for j in range(m+1)]for i in range(n+1)]
        match[0][0] = True

        for i in range(1,m+1):
            if i>1 and p[i-1] == '*':
                match[0][i] = match[0][i-2]
        
        for i in range(1,n+1):
            for j in range(1, m+1):
                if p[j-1] == '.' or p[j-1] == s[i-1]:
                    match[i][j] = match[i-1][j-1]
                elif j>1 and p[j-1] == '*':
                    if p[j-2] == s[i-1] or p[j-2] == '.':
                        match[i][j] = match[i][j-2] or match[i-1][j]
                    else:
                        match[i][j] = match[i][j-2]
        return match[n][m]

match = Solution()
s, p = "xaabyc", "xa*b.c"
print(match.isMatch(s,p)) 