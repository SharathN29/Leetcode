"""
Reorder Log Files : https://leetcode.com/problems/reorder-data-in-log-files/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 13 2019
Runtime: 24 ms, faster than 64.66% of Python online submissions for Reorder Data in Log Files.
Memory Usage: 11.9 MB, less than 80.00% of Python online submissions for Reorder Data in Log Files.
"""
class Solution:
    def reorderLogFiles(self, logs):
        digits = []
        letters = []
        for log in logs:
            if log.split()[1].isdigit():
                digits.append(log)
            else:
                letters.append(log)

        letters.sort(key = lambda x: x.split()[0])
        letters.sort(key = lambda x: x.split()[1:])
        result = letters + digits
        return result

logFiles = Solution()
logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
print(logFiles.reorderLogFiles(logs))