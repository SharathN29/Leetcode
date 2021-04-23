# https://leetcode.com/problems/transpose-matrix/

class Solution:
    def transpose(self, A: List[List[int]]) -> List[List[int]]:
        sol = []

        for c in range(len(A[0])):
            temp = []
            for r in range(len(A)):
                temp.append(A[r][c])

            sol.append(temp)

        return sol
