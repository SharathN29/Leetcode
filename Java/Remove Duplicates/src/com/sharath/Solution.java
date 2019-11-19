package com.sharath;

public class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length < 2) return nums.length;
        int id = 1;
        for(int i = 1; i < nums.length; i++)
            if(nums[i] != nums[i-1])
                nums[id++] = nums[i];
        return id;
    }
}
