// https://leetcode.com/problems/binary-search/

class Solution {
    public int search(int[] nums, int target) {
        int left = 0, right = nums.length - 1; 
        
        while (left <= right) {
            int pivotal = (left + right) / 2; 
            if(nums[pivotal] == target) return pivotal; 
            else if(nums[pivotal] > target) right = pivotal - 1;
            else left = pivotal + 1; 
        }
        return -1; 
    }
}