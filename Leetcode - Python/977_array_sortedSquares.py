import collections
from typing import List


def sortedSquares(self, nums: List[int]) -> List[int]:
    res = collections.deque()
    l, r = 0, len(nums) - 1
    while l <= r:
        left, right = abs(nums[l]), abs(nums[r])
        if left > right:
            res.appendleft(left * left)
            l += 1
        else:
            res.appendleft(right * right)
            r -= 1

    return list(res)

    nums = [-5, -2, 1, 4, 8]
    print(sortedSquares(nums))
