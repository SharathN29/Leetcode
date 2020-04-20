// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
    public boolean search(int[] nums, int target) {
        
        int left = 0, right = nums.length-1;
    
        while(left <= right) {
            int mid = left + (right-left) / 2;
            if(nums[mid] == target) return true;
            if(nums[mid] == nums[left] && nums[mid] == nums[right]) {
                left++;
                right--;
            } else if(nums[left] <= nums[mid]) {
                if(nums[left] <= target && nums[mid] > target) right = mid-1;
                else left = mid+1;
            } else {
                if(nums[mid] < target && nums[right] >= target) left = mid+1;
                else right = mid-1;
            }
        }
        return false; 
    }
}