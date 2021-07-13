# https://leetcode.com/problems/reverse-integer/

class Solution:
    def reverse(self, x: int) -> int:
        res = 0
        if x < 0:
            res = -int(str(str(x)[1:])[::-1])
            if res < -2147483648:
                return 0
        else:
            res = int(str(x)[::-1])
            if res > 2147483648:
                return 0
        return res 