// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int res = 0, j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i-1] >= nums[i]) j = i;
            res = Math.max(res, i - j + 1);
        }
        return res;
    }
}