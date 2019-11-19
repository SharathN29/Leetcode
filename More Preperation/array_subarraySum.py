"""
Subarray Sum Equals K : https://leetcode.com/problems/subarray-sum-equals-k/
Author : Sharath Nagendra

Passes all leetcode test cases as on Oct 4 2019.
Runtime: 92 ms, faster than 77.37% of Python online submissions for Subarray Sum Equals K.
Memory Usage: 13.6 MB, less than 100.00% of Python online submissions for Subarray Sum Equals K.
"""
def subarraySum(num, k):
    count, p, d = 0, 0, {0:1}
    for i in num:
        p += i
        if p-k in d: count += d[p-k]
        if p not in d: d[p] = 1
        else: d[p] += 1
    return count

num, k = [1,1,1], 1
print(subarraySum(num,k))