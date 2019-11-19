"""
Replace Words : https://leetcode.com/problems/replace-words/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 9 2019
Runtime: 124 ms, faster than 75.99% of Python online submissions for Replace Words.
Memory Usage: 52.1 MB, less than 44.44% of Python online submissions for Replace Words.
"""
import collections

class TrieNode():
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.isCompleteWord = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        current = self.root
        for letter in word:
            current = current.children[letter]
        current.isCompleteWord = True

    def getRoot(self, word):
        ans = ""
        current = self.root
        for letter in word:
            if letter in current.children:
                ans += letter
                current = current.children.get(letter)
                if current.isCompleteWord:
                    return ans
            else: break
        return word

class Solution(object):
    def replaceWords(self, dict, sentence):
        res = []
        trie = Trie()
        for word in dict:
            trie.insert(word)
        
        for word in sentence.split():
            res.append(trie.getRoot(word))
        return ' '.join(res)

replace = Solution()
dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
print(replace.replaceWords(dict, sentence))