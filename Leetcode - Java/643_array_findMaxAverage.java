// https://leetcode.com/problems/maximum-average-subarray-i/

class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int i = 0, windowSum = 0;
        double maxAve = -Double.MAX_VALUE; 
        
        for (int j = 0; j < nums.length; j++) {
            windowSum += nums[j];
            if (j >= k - 1) {
                double avg = windowSum / 1.0 / k;
                maxAve = Math.max(maxAve, avg);
                windowSum -= nums[i++];
            }
        }
        return maxAve;
    }
}