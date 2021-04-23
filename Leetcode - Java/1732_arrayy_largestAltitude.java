// https://leetcode.com/problems/find-the-highest-altitude/

class Solution {
    public int largestAltitude(int[] gain) {
        int currAltitude = 0, maxAltitude = 0;
        for (int g : gain) {
            currAltitude += g;
            maxAltitude = Math.max(maxAltitude, currAltitude);
        }
        return maxAltitude;
    }
}