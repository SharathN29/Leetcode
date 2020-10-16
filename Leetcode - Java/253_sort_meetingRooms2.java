// https://leetcode.com/problems/meeting-rooms-ii/

class Solution {
    public int minMeetingRooms(int[][] intervals) {
        if (intervals.length == 0) {
            return 0;
        }
        
        PriorityQueue<Integer> allocator = new PriorityQueue<Integer>(intervals.length, (a, b) -> Integer.compare(a, b));
        
        Arrays.sort(intervals, (x, y) -> Integer.compare(x[0], y[0]));
        
        allocator.add(intervals[0][1]);
        
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= allocator.peek()) {
                allocator.poll(); 
            }
            allocator.add(intervals[i][1]);
        }
        return allocator.size();
    }
}