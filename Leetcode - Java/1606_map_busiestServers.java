// https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/

class Solution {
    public List<Integer> busiestServers(int k, int[] arrival, int[] load) {
        int[] counter = new int[k];
        TreeSet<Integer> available = new TreeSet<>();
        for (int num = 0; num < k; num++) {
            available.add(num);
        }

        Queue<int[]> busyServers = new PriorityQueue<>((a, b) -> a[0] - b[0]);

        for (int idx = 0; idx < arrival.length; idx++) {
            int currTime = arrival[idx];
            int endTime = currTime + load[idx];
            while (!busyServers.isEmpty() && busyServers.peek()[0] <= currTime) {
                int freedServer = busyServers.poll()[1];
                available.add(freedServer);
            }
            if (available.size() == 0) continue;
            Integer assignServer = available.ceiling(idx % k);
            if (assignServer == null) {
                assignServer = available.first();
            }
            counter[assignServer]++;
            available.remove(assignServer);
            busyServers.offer(new int[] {endTime, assignServer});
        }
        return findMaxInCounter(counter);
    }
    
    public List<Integer> findMaxInCounter(int[] counter) {
        int max = 0;
        for (int i = 0; i < counter.length; i++) {
            max = Math.max(max, counter[i]);
        }
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < counter.length; i++) {
            if (counter[i] == max) {
                result.add(i);
            }
        }
        return result;
    }
}