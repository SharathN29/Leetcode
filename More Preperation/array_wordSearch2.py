"""Word Search 2 : https://leetcode.com/problems/word-search-ii/
Author : Sharath Nagendra

Passes all leetcode test cases as of OCt 9 2019
Runtime: 468 ms, faster than 36.56% of Python online submissions for Word Search II.
Memory Usage: 47.9 MB, less than 30.44% of Python online submissions for Word Search II.
"""
import collections

class TrieNode():
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.isCompleteWord = False

class Trie(object):
    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word):
        node = self.root
        for letter in word:
            node = node.children[letter]
        node.isCompleteWord = True

class Solution(object):
    def findWords(self, board, words):
        res = []
        trie = Trie()
        node = trie.root
        for w in words:
            trie.addWord(w)
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.traverse(board, node, i, j, "", res)
        return res

    def traverse(self, board, node, i, j, path, res):
        if node.isCompleteWord:
            res.append(path)
            node.isCompleteWord = False
        
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
            return 

        temp = board[i][j]
        node = node.children.get(temp)
        if not node:
            return 
        board[i][j] = "#"
        self.traverse(board, node, i+1, j, path+temp, res)
        self.traverse(board, node, i-1, j, path+temp, res)
        self.traverse(board, node, i, j-1, path+temp, res)
        self.traverse(board, node, i, j+1, path+temp, res)
        board[i][j] = temp

fw = Solution()
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]
print(fw.findWords(board, words))