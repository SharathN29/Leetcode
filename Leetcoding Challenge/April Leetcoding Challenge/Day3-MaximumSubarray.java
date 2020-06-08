// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3285/

class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum = nums[0];
        for(int i = 1; i < nums.length; i++) {
            nums[i] = Math.max(nums[i], nums[i] + nums[i-1]);
            if(nums[i] > maxSum)
                maxSum = nums[i];
        }
        return maxSum;
    }
}