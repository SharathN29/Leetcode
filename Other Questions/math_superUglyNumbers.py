"""
Super Ugly Numbers : https://leetcode.com/problems/super-ugly-number/
Author : Sharath Nagendra

Passes all leetcode test cases as on Oct 2, 2019
Runtime: 340 ms, faster than 89.46% of Python online submissions for Super Ugly Number.
Memory Usage: 17.9 MB, less than 25.00% of Python online submissions for Super Ugly Number.
"""
def nthSuperUglyNumber(n, primes):
    size = len(primes)
    ugly, dp, index, uglyNums = 1, [1], [0]*size, [1]*size
    for i in range(1,n):
        for j in range(0,size):
            if uglyNums[j] == ugly:
                uglyNums[j] = dp[index[j]]*primes[j]
                index[j] += 1
        ugly= min(uglyNums)
        dp.append(ugly)
    return dp[-1]

n, primes = 12, [2,7,13,19]
print(nthSuperUglyNumber(n, primes))