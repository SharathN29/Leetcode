// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3357/

class Solution {
    public void sortColors(int[] nums) {
        int low = 0, mid = 0, high = nums.length-1;
        while (mid <= high) {
            if (nums[mid] == 0) swap(mid++, low++, nums);
            else if (nums[mid] == 1) mid++;
            else if (nums[mid] == 2) swap(mid, high--, nums);
        }
    }
    
    private void swap(int i, int j, int[] nums) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}