// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
    public int findMinArrowShots(int[][] points) {
        if (points.length == 0) return 0;
        
        Arrays.sort(points, (x, y) -> x[1] - y[1]);
        
        int arrows = 1;
        int xStart, xEnd, firstEnd = points[0][1];
        
        for (int[] p : points) {
            xStart = p[0];
            xEnd = p[1];
            
            if (firstEnd < xStart) {
                arrows++;
                firstEnd = xEnd;
            }
        }
        
        return arrows; 
    }
}