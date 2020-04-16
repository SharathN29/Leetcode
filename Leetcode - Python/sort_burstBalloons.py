"""
Minimum Number of Arrows to Burst Balloons : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 6 2019
Runtime: 376 ms, faster than 72.54% of Python online submissions for Minimum Number of Arrows to Burst Balloons.
Memory Usage: 17.4 MB, less than 25.00% of Python online submissions for Minimum Number of Arrows to Burst Balloons.
"""
def findMinArrowShots(points):
    points.sort(key = lambda x:x[1])
    res, end = 0, -float('inf')
    for p in points:
        if p[0] > end:
            res += 1
            end = p[1]
    return res

points = [[10,16], [2,8], [1,6], [7,12]]
print(findMinArrowShots(points))