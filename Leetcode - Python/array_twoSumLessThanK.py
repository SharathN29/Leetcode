"""
Two Sum Less Than K : https://leetcode.com/problems/two-sum-less-than-k/
Author : Sharath Nagendra

Passes all leetcode test cases as on Oct 4 2019.
Runtime: 28 ms, faster than 76.89% of Python online submissions for Two Sum Less Than K.
Memory Usage: 11.6 MB, less than 66.67% of Python online submissions for Two Sum Less Than K.
"""
def twoSumLessThanK(A,K):
    a = sorted(A)
    l, r = 0, len(a)-1
    ans = -1
    while l < r:
        if a[l] + a[r] < K:
            ans = max(ans, a[l] + a[r])
            l += 1
        else: r -= 1
    return ans

A, K = [34,23,1,24,75,33,54,8], 60
print(twoSumLessThanK(A,K))