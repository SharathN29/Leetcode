// https://leetcode.com/problems/shuffle-the-array/

class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] res = new int[2*n];
        
        int i = 0, j = n, idx = 0;
        while (j < nums.length) {
            res[idx++] = nums[i++];
            res[idx++] = nums[j++];
        }
        return res; 
    }
}