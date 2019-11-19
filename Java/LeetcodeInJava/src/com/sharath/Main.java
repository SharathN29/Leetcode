package com.sharath;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
	    // Two Sum : https://leetcode.com/problems/two-sum/
        TwoSum twoSum = new TwoSum();
        int[] twoSumArr = {2, 7, 11, 15};
        int twoSumTarget = 9;
        int[] twoSumRes = twoSum.twoSum(twoSumArr, twoSumTarget);
        System.out.println(Arrays.toString(twoSumRes));

        //Remove Duplicates : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
        RemDuplicates remDuplicates = new RemDuplicates();
        int[] remDupArr = {0,0,1,1,1,2,2,3,3,4};
        System.out.println(remDuplicates.removeDuplicates(remDupArr));

        //Remove Elements : https://leetcode.com/problems/remove-element/
        RemoveElements removeElements = new RemoveElements();
        int[] remEleArr = {0,1,2,2,3,0,4,2};
        int remEleVal = 2;
        System.out.println(removeElements.removeElement(remEleArr, remEleVal));
    }
}
