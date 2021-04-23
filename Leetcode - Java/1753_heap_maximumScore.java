// https://leetcode.com/problems/maximum-score-from-removing-stones/

class Solution {
    public int maximumScore(int a, int b, int c) {
        Queue<Integer> pq = new PriorityQueue<>((x, y) -> y - x);
        pq.offer(a);
        pq.offer(b);
        pq.offer(c);
        int score = 0;
        
        while (pq.size() > 1) {
            int x = pq.poll();
            int y = pq.poll();
            x -= 1;
            y -= 1;
            if (x > 0) pq.offer(x);
            if (y > 0) pq.offer(y);
            score++;
        }
        return score;
    }
}