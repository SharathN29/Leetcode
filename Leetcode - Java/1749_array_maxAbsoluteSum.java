// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int sum = 0, maxsum = 0, minsum = 0;
        for (int n : nums) {
            sum += n;
            maxsum = Math.max(maxsum, sum);
            minsum = Math.min(minsum, sum);
        }
        return maxsum - minsum;
    }
}