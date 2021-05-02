// https://leetcode.com/problems/seat-reservation-manager/

class SeatManager {
    
    private TreeSet<Integer> seats;

    public SeatManager(int n) {
        seats = new TreeSet<Integer>();
        for (int seatNum = 1; seatNum <= n; seatNum++) {
            seats.add(seatNum);
        }
    }
    
    public int reserve() {
        return seats.pollFirst();
    }
    
    public void unreserve(int seatNumber) {
        seats.add(seatNumber);
    }
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager obj = new SeatManager(n);
 * int param_1 = obj.reserve();
 * obj.unreserve(seatNumber);
 */
