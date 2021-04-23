// https://leetcode.com/problems/sort-array-by-increasing-frequency/

class Solution {
    public int[] frequencySort(int[] nums) {
        Map<Integer, Integer> map = new HashMap();
        for (int n : nums) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }
        Queue<Integer> pq = new PriorityQueue<>((i, j) -> map.get(i) == map.get(j) ? j - i : map.get(i) - map.get(j));
        for (int n : nums) {
            pq.offer(n);
        }
        int i = 0;
        int[] res = new int[nums.length];
        while(!pq.isEmpty()) {
            res[i++] = pq.poll();
        }
        return res;
    }
}