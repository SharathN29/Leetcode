// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

class Solution {
    public int largestSumAfterKNegations(int[] A, int K) {
        Queue<Integer> pq = new PriorityQueue();
        for (int a : A) {
            pq.add(a);
        }
        
        while (K-- > 0) {
            pq.add(-pq.poll());
        }
        
        int sum = 0;
       for(int i = 0; i < A.length; i++){
            sum += pq.poll();
        }
        
        return sum;
    }
}