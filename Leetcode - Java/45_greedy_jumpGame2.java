// https://leetcode.com/problems/jump-game-ii/

class Solution {
    public int jump(int[] nums) {
        int n = nums.length, start = 0, end = 0, steps = 0;
        while(end < n-1) {
            steps++;
            int maxEnd = end + 1;
            for(int i = start; i <= end; i++) {
                if(i + nums[i] >= n - 1) 
                    return steps; 
                maxEnd = Math.max(maxEnd, i+nums[i]);
            }
            start = end + 1;
            end = maxEnd; 
        }
        return steps;
    }
}