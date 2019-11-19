"""
Word Ladder : https://leetcode.com/problems/word-ladder/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 7 2019
Runtime: 108 ms, faster than 84.60% of Python online submissions for Word Ladder.
Memory Usage: 16.2 MB, less than 27.03% of Python online submissions for Word Ladder.
"""
import collections
from collections import defaultdict

class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        if endWord not in wordList or not endWord or not beginWord or not wordList:
            return 0

        allCombination = defaultdict(list)
        for word in wordList:
            for i in range(len(beginWord)):
                allCombination[word[:i]+"*"+word[i+1:]].append(word)

        queue = collections.deque([(beginWord,1)])
        visited = {beginWord: True}
        while queue:
            currentWord, level = queue.popleft()
            for i in range(len(beginWord)):
                intermediateWord = currentWord[:i] + "*" + currentWord[i+1:]
                for word in allCombination[intermediateWord]:
                    if word == endWord:
                        return level+1
                    
                    if word not in visited:
                        visited[word] = True
                        queue.append((word, level+1))
                    allCombination[intermediateWord] = []
        return 0

beginWord, endWord, wordList = "hit", "cog", ["hot","dot","dog","lot","log","cog"]
wl = Solution()
print(wl.ladderLength(beginWord, endWord, wordList))
