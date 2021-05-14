// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/

class Solution {
    public int nearestValidPoint(int x, int y, int[][] points) {
        int minDist = Integer.MAX_VALUE;
        int minIndex = -1;
        for (int i = 0; i < points.length; i++) {
            if (points[i][0] == x || points[i][1] == y){
                int manhattanDist = Math.abs(x - points[i][0]) + Math.abs(y - points[i][1]); 
                if(manhattanDist < minDist){
                    minDist = manhattanDist;
                    minIndex = i;
                }
            }          
        }
        return minIndex;
    } 
}