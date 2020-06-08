// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3345/

class Solution {
	public int[][] kClosest(int[][] points, int K) {
	    PriorityQueue<int[]> pq = new PriorityQueue<int[]>((p1, p2) -> p2[0] * p2[0] + p2[1] * p2[1] - p1[0] * p1[0] - p1[1] * p1[1]);
	    for (int[] p : points) {
	        pq.offer(p);
	        if (pq.size() > K) {
	            pq.poll();
	        }
	    }
	    int[][] res = new int[K][2];
	    while (K > 0) {
	        res[--K] = pq.poll();
	    }
	    return res;
	}
}