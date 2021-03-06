// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
    public int[] searchRange(int[] nums, int target) {
        int left = 0, right = nums.length - 1; 
        int[] res = new int[2];
        
        if (nums == null || nums.length == 0) {
            return new int[]{-1, -1};
        }
        
        while (left < right) {
            int mid = left + (right - left) / 2; 
            if (target > nums[mid]) {
                left = mid + 1; 
            } else {
                right = mid; 
            }
        }
        
        if(target == nums[left]) {
            res[0] = left; 
        } else {
            res[0] = -1; 
        }
        
        right = nums.length - 1; 
        while (left < right) {
            int mid = (left + (right - left) / 2) + 1; 
            if(target < nums[mid]) {
                right = mid - 1; 
            } else {
                left = mid; 
            }
        }
        
        if (target == nums[right]) {
            res[1] = right;
        } else {
            res[1] = -1; 
        }
        
        return res; 
    }
}

