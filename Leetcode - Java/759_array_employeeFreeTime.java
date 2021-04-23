// https://leetcode.com/problems/employee-free-time/

/*
// Definition for an Interval.
class Interval {
    public int start;
    public int end;

    public Interval() {}

    public Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
    public List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
        List<Interval> result = new ArrayList();
        Queue<Interval> pq = new PriorityQueue<>((a, b) -> a.start - b.start);
        schedule.forEach(e -> pq.addAll(e));
        
        Interval temp = pq.poll();
        
        while (!pq.isEmpty()) {
            if (temp.end < pq.peek().start) {
                result.add(new Interval(temp.end, pq.peek().start));
                temp = pq.poll();
            } else {
                temp = temp.end > pq.peek().end ? temp : pq.peek();
                pq.poll();
            }
        }
        return result;
    }
}