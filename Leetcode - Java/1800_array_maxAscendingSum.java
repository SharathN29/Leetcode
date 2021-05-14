// https://leetcode.com/problems/maximum-ascending-subarray-sum/

class Solution {
    public int maxAscendingSum(int[] nums) {
        int maxPossibleSum = nums[0];
        int currSum = nums[0]; 
        
        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] < nums[i]) {
                currSum += nums[i];
                maxPossibleSum = Math.max(maxPossibleSum, currSum);
            } else currSum = nums[i];
        }
        
        return maxPossibleSum;
    }
}