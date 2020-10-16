// https://leetcode.com/problems/house-robber-ii/

class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n < 2) return n == 1 ? nums[0] : 0;
        return Math.max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
    
    public int robber(int[] nums, int l, int r) {
        int pre = 0, curr = 0;
        for (int i = l; i <= r; i++) {
            int temp = Math.max(pre + nums[i], curr);
            pre = curr;
            curr = temp;
        }
        return curr;
    }
}