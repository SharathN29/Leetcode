# https://leetcode.com/problems/sort-array-by-parity/


class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        left, right = 0, len(A) - 1
        while left < right:
            if A[left] % 2 > A[right] % 2:
                A[left], A[right] = A[right], A[left]
            if A[left] % 2 == 0:
                left += 1
            if A[right] % 2 == 1:
                right -= 1

        return A
