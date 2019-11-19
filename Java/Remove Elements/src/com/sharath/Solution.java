package com.sharath;

public class Solution {
    public int removeElement(int[] nums, int val) {
        int len = nums.length;
        int id = 0;
        for(int i = 0; i < len; i++)
            if(nums[i] != val)
                nums[id++] = nums[i];
        return id;
    }
}
