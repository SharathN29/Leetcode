"""
Word Search : https://leetcode.com/problems/word-search/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 9 2019
Runtime: 344 ms, faster than 60.44% of Python online submissions for Word Search.
Memory Usage: 16.4 MB, less than 22.22% of Python online submissions for Word Search.
"""
class Solution(object):
    def exist(self, board, word):
        if not board:
            return False
        r, c = len(board), len(board[0])
        visited = [[False for i in range(c)] for j in range(r)]
        for i in range(r):
            for j in range(c):
                if self.dfs(board, word, visited, i, j):
                    return True
        return False
        
    def dfs(self, board, word, visited, i, j):
        if not word:
            return True
        if i < 0 or i == len(board) or j < 0 or j == len(board[0]) \
        or visited[i][j] or word[0] != board[i][j]:
            return False
        visited[i][j] = True
        res = self.dfs(board, word[1:], visited, i+1, j) or \
            self.dfs(board, word[1:], visited, i-1, j) or \
            self.dfs(board, word[1:], visited, i, j-1) or \
            self.dfs(board, word[1:], visited, i, j+1)
        visited[i][j] = False
        return res

wordSrch = Solution()
board = [
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED"
print(wordSrch.exist(board, word))
