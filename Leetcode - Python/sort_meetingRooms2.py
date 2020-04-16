"""
Meeting Rooms II : https://leetcode.com/problems/meeting-rooms-ii/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 6 2019
Runtime: 68 ms, faster than 32.47% of Python online submissions for Meeting Rooms II.
Memory Usage: 15.2 MB, less than 45.24% of Python online submissions for Meeting Rooms II.
"""
import heapq

def minMeetingRooms(intervals):
    intervals.sort(key=lambda x: x[0])
    heap = []
    for i in intervals:
        if heap and i[0] >= heap[0]:
            heapq.heapreplace(heap, i[1])
        else: heapq.heappush(heap, i[1])
    return len(heap)

intervals = [[7,10],[2,4]]
print(minMeetingRooms(intervals))