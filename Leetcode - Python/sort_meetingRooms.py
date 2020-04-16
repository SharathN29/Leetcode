"""
Meeting Rooms : https://leetcode.com/problems/meeting-rooms/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 6 2019
Runtime: 60 ms, faster than 61.67% of Python online submissions for Meeting Rooms.
Memory Usage: 15 MB, less than 92.31% of Python online submissions for Meeting Rooms.
"""
def canAttendMeetings(intervals):
    intervals.sort(key = lambda x:x[0])
    for p,q in zip(intervals, intervals[1:]):
        if q[0] < p[1]:
            return False
    return True

intervals = [[0,30],[5,10],[15,20]]
print(canAttendMeetings(intervals))