// https://leetcode.com/problems/minimum-cost-to-connect-sticks/

class Solution {
    public int connectSticks(int[] sticks) {
        Queue<Integer> queue = new PriorityQueue<>();
        for (int n : sticks) {
            queue.offer(n);
        }
        int cost = 0;
        int s1 = 0, s2 = 0;
        
        while (queue.size() > 1) {
            s1 = queue.poll();
            s2 = queue.poll();
            cost += s1 + s2;
            queue.offer(s1 + s2);
        }
        return cost;
    }
}