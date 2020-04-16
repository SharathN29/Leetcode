"""
Implement Trie (Prefix Tree) : https://leetcode.com/problems/implement-trie-prefix-tree/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 9 2019
Runtime: 188 ms, faster than 60.33% of Python online submissions for Implement Trie (Prefix Tree).
Memory Usage: 38.8 MB, less than 23.53% of Python online submissions for Implement Trie (Prefix Tree).
"""
import collections

class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.isEndOfWord = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        current = self.root
        for letter in word:
            current = current.children[letter]
        current.isEndOfWord = True

    def search(self, word):
        current = self.root
        for letter in word:
            current = current.children.get(letter)
            if current is None:
                return False
        return current.isEndOfWord

    def startsWith(self, prefix):
        current = self.root
        for letter in prefix:
            current = current.children.get(letter)
            if current is None:
                return False
        return True

trie = Trie()
trie.insert("leetcode")
trie.insert("look")
trie.insert("leet")
print(trie.search("leet"))
print(trie.startsWith("mi"))