// https://leetcode.com/problems/missing-number/

class Solution {
    public int missingNumber(int[] nums) {
        int expectedSum = nums.length * (nums.length + 1) / 2;
        int actualSum = 0;
        for (int n : nums) {
            actualSum += n;
        }
        return expectedSum - actualSum;
    }
}