"""
Merge Intervals : https://leetcode.com/problems/merge-intervals/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 6 2019
"""
def mergeIntervals(intervals):
    out = []
    intervals.sort(key = lambda x: x[0])
    for i in intervals:
        if out and i[0] <= out[-1][1]:
            out[-1][1] = max(out[-1[1], i[1]])
        else:
            out += i,
    return out

intervals = [[1,3],[2,6],[8,10],[15,18]]
print(mergeIntervals(intervals))