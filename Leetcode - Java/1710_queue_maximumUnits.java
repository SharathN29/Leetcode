// https://leetcode.com/problems/maximum-units-on-a-truck/

class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        Queue<int[]> queue = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        queue.addAll(Arrays.asList(boxTypes));
        int boxUnitCount = 0;
        
        while (!queue.isEmpty()) {
            int[] top = queue.poll();
            int boxCount = Math.min(truckSize, top[0]);
            boxUnitCount += boxCount * top[1];
            truckSize -= boxCount;
            
            if (truckSize == 0) break;
        }
        return boxUnitCount;
    }
}