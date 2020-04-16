// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int count = 0, res = 0;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] == 1)
                count++;
            else if(nums[i] != 1) {
                res = Math.max(res, count);
                count = 0;
            }
        }      
        return Math.max(count, res);
    }
}