"""
Decode String : https://leetcode.com/problems/decode-string/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 21 2019
Runtime: 20 ms, faster than 36.51% of Python online submissions for Decode String.
Memory Usage: 11.8 MB, less than 39.22% of Python online submissions for Decode String.
"""
class Solution(object):
    def decodeString(self, s):
        stack, curNum, curString = [], 0, ''
        for c in s:
            if c == '[':
                stack.append(curString)
                stack.append(curNum)
                curString = ''
                curNum = 0
            elif c == ']':
                num = stack.pop()
                prevString = stack.pop()
                curString = prevString + num*curString
            elif c.isdigit():
                curNum = curNum*10 + int(c)
            else: curString += c
        return curString

ds = Solution()
s = "2[abc]3[cd]ef"
print(ds.decodeString(s))