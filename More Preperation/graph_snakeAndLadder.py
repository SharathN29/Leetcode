"""
Snakes and Ladders : https://leetcode.com/problems/snakes-and-ladders/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 12 2019
"""
class QueueEntry(object):
    def __init__(self, v = 0, dist = 0):
        self.v = v
        self.dist = dist

class Solution(object):
    def snakesAndLadders(self, board):
        n = len(board) * len(board[0])
        visited = [False] * n
        queue = []
        visited[0] = True
        queue.append(QueueEntry(0,0))
        qe = QueueEntry()
        while queue:
            qe = queue.pop() 
            v = qe.v
            if v == n-1: break
            j = v+1
            while j <= v+6 and j < n:
                if visited[j] is False:
                    a = QueueEntry()
                    a.dist = qe.dist+1
                    visited[j] = True

                    a.v = board[j] if board[j] != -1 else j 
                    queue.append(a)
                j += 1
        return qe.dist

snakes = Solution()
board = [
[-1,-1,-1,-1,-1,-1],
[-1,-1,-1,-1,-1,-1],
[-1,-1,-1,-1,-1,-1],
[-1,35,-1,-1,13,-1],
[-1,-1,-1,-1,-1,-1],
[-1,15,-1,-1,-1,-1]]
print(snakes.snakesAndLadders(board))
