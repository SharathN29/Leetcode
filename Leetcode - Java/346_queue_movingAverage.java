// https://leetcode.com/problems/moving-average-from-data-stream/

class MovingAverage {
    
    Queue<Integer> q; 
    double sum = 0;
    int size;

    /** Initialize your data structure here. */
    public MovingAverage(int size) {
        q = new LinkedList();
        this.size = size;
    }
    
    public double next(int val) {
        if (q.size() == size) {
            sum -= q.poll();
        }
        q.offer(val);
        sum += val;
        return sum / q.size();
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */