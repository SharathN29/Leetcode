// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = 0;
        for(int num : nums) {
            n ^= num;
        }
        return n;
    }
}