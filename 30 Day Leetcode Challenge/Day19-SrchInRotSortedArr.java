// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3304/

class Solution {
    public int search(int[] nums, int target) {
        int left = 0, right = nums.length-1; 
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid; 
            else if(nums[mid] >= nums[left]) {
                if(target >= nums[left] && target < nums[mid]) right = mid-1;
                else left = mid + 1;
            } else {
                if(target <= nums[right] && target > nums[mid]) left = mid+1;
                else right = mid-1; 
            }
        }
        return -1;
    }
}