// https://leetcode.com/problems/set-mismatch/

class Solution {
    public int[] findErrorNums(int[] nums) {
        if (nums == null || nums.length == 0) return new int[0];
        int duplicate = -1, missing = -1;
        
        for (int i = 0; i < nums.length; i++) {
            int index = Math.abs(nums[i]) - 1;
            if (nums[index] < 0) duplicate = index + 1;
            else nums[index] *= -1;
        }
        
        for (int i = 0, j = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                missing = i + 1;
            }
        }
        
        return new int[]{duplicate, missing};
    }
}