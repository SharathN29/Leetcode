# https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/

class Solution:
    def canThreePartsEqualSum(self, arr: List[int]) -> bool:
        l, r, s = 1, len(arr) - 2, sum(arr)
        leftsum, rightsum, average = arr[0], arr[-1], s // 3

        while l <= r:
            if l < r and leftsum != average:
                leftsum += arr[l]
                l += 1

            if l < r and rightsum != average:
                rightsum += arr[r]
                r -= 1

            if leftsum == average and rightsum == average and s % 3 == 0:
                return True

            if l == r:
                break

        return False
