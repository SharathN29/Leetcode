// https://leetcode.com/problems/largest-number-at-least-twice-of-others/

class Solution {
    public int dominantIndex(int[] nums) {
        int maxindex = 0;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] > nums[maxindex]) 
                maxindex = i;
        }
        
        for(int i = 0; i < nums.length; i++) {
            if(i != maxindex && nums[maxindex] < 2 * nums[i])
                return -1;
        }
        return maxindex;
    }
}