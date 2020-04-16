"""
Ugly Number III : https://leetcode.com/contest/weekly-contest-155/problems/ugly-number-iii/
Author : Sharath Nagendra

Passes as leetcode test cases as on Sept 27 2019
Runtime: 36 ms, faster than 85.11% of Python3 online submissions for Ugly Number III.
Memory Usage: 13.8 MB, less than 100.00% of Python3 online submissions for Ugly Number III.
"""
import math
def nthUglyNumber(n, a, b, c):
    def lcm(a,b):
        return a*b // math.gcd(a,b)
    
    def countUgly(n, a, b, c, ab, bc, ca, abc):
        ans = n // a + n // b + n // c
        ans -= n // ab + n // bc + n // ca
        ans += n // abc
        return ans

    ab, bc, ca = lcm(a,b), lcm(b,c), lcm(c,a)
    abc = lcm(ab,c)
    low = 1
    high = 2 * 10 ** 9
    while low < high:
        mid = low+(high-low)//2
        if countUgly(mid, a, b, c, ab, bc, ca, abc) < n:
            low = mid + 1
        else:
            high = mid 
    return low

n, a, b, c = 3, 2, 3, 5
print(nthUglyNumber(n, a, b, c))