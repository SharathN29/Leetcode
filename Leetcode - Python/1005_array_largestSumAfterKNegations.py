# https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

import heapq

class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        heapq.heapify(A)
        while K and A[0] < 0:
            heapq.heapreplace(A, -A[0])
            K -= 1
        
        if K % 2:
            heapq.heapreplace(A, -A[0])

        return sum(A)
