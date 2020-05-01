// https://leetcode.com/problems/jump-game/

class Solution {
    public boolean canJump(int[] nums) {
        int last_position = nums.length-1;
        for(int i = last_position; i >= 0; i--) {
            if(i + nums[i] >= last_position) {
                last_position = i;
            }
        }
        return last_position == 0;
    }
}