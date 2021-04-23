// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> map = new HashMap();
        for (int a : arr) {
            map.put(a, map.getOrDefault(a, 0)+1);
        }
        Queue<Integer> pq = new PriorityQueue<>((a,b)->map.get(a) - map.get(b));
        pq.addAll(map.keySet());
        
        while (k > 0) {
            k -= map.get(pq.poll());
        }
        return k < 0 ? pq.size() + 1 : pq.size();
    }
}