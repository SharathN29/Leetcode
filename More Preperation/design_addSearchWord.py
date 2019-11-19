"""
Add and Search Word - Data structure design : https://leetcode.com/problems/add-and-search-word-data-structure-design/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 9 2019
Runtime: 424 ms, faster than 31.10% of Python online submissions for Add and Search Word - Data structure design.
Memory Usage: 36.3 MB, less than 7.14% of Python online submissions for Add and Search Word - Data structure design.
"""
import collections

class TrieNode():
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.isCompleteWord = False

class WordDictionary(object):
    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word):
        node = self.root
        for letter in word:
            node = node.children[letter]
        node.isCompleteWord = True
    
    def search(self, word):
        node = self.root
        self.res = False
        self.dfs(node, word)
        return self.res
    
    def dfs(self, node, word):
        if not word: 
            if node.isCompleteWord:
                self.res = True
            return 

        if word[0] == ".":
            for n in node.children.values():
                self.dfs(n, word[1:])
        else:
            node = node.children.get(word[0])
            if not node:
                return 
            self.dfs(node, word[1:])

wd = WordDictionary()
wd.addWord("dog")
wd.addWord("mob")
wd.addWord("peet")
print(wd.search("peg"))
print(wd.search(".og"))
print(wd.search("peet"))