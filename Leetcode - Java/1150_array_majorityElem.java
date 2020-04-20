// https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/

class Solution {
    public boolean isMajorityElement(int[] nums, int target) {
        int n = nums.length; 
        int count = 0;
        for(int num : nums) {
            if(num == target) count++;
            if(count > n/2) return true;
        }
        return false; 
    }
}