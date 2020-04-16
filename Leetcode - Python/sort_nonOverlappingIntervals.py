"""
Non-overlapping Intervals : https://leetcode.com/problems/non-overlapping-intervals/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 6 2019
Runtime: 52 ms, faster than 83.17% of Python online submissions for Non-overlapping Intervals.
Memory Usage: 15.1 MB, less than 80.00% of Python online submissions for Non-overlapping Intervals.
"""
def eraseOverlapIntervals(intervals):
    erased, end = 0, float('-inf')
    intervals.sort(key = lambda x: x[1])
    for i in intervals:
        if i[0] >= end:
            end = i[1]
        else:
            erased += 1
    return erased

intervals = [[1,2],[2,3],[3,4],[1,3]]
print(eraseOverlapIntervals(intervals))