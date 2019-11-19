//Two Sum : https://leetcode.com/problems/two-sum/
//Author : Sharath Nagendra
//
//Passes all leetcode test cases as of Nov 12 2019.
//Runtime: 2 ms, faster than 98.95% of Java online submissions for Two Sum.
//Memory Usage: 38.4 MB, less than 72.70% of Java online submissions for Two Sum.


package com.sharath;

import com.sharath.Solution;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
	    Solution solution = new Solution();
	    int[] nums = {2, 7, 11, 15};
	    int target = 9;

	    int[] result = solution.twoSum(nums, target);
        System.out.println(Arrays.toString(result));
    }
}
