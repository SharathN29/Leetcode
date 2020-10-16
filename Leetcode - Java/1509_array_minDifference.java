// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

class Solution {
    public int minDifference(int[] nums) {
        int numsLen = nums.length, res = Integer.MAX_VALUE; 
        if (numsLen < 5) return 0; 
        Arrays.sort(nums);
        
        for (int i = 0; i < 4; i++) {
            res = Math.min(res, nums[numsLen - 4 + i] - nums[i]);
        }
        
        return res;
    }
}