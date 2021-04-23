// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3356/

class Solution {
    public int searchInsert(int[] nums, int target) {
        int low = 0, high = nums.length-1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] == target) return mid; 
            else if (nums[mid] < target) low = mid + 1; 
            else high = mid - 1;
        }
        return low; 
    }
}
