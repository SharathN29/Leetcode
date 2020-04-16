// https://leetcode.com/problems/search-insert-position/

class Solution {
    // public int searchInsert(int[] nums, int target) {
    //     int i = 0;
    //     while(i < nums.length && nums[i] < target) i++;
    //     return i;
    // }

    public int searchInsert(int[] nums, int target) {
        int low = 0, high = nums.length-1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] == target) return mid; 
            else if(nums[mid] < target ) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
}