// https://leetcode.com/problems/ways-to-make-a-fair-array/

class Solution {
    public int waysToMakeFair(int[] nums) {
        int res = 0; 
        int rightEven = 0, rightOdd = 0;
        int n = nums.length;
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) rightEven += nums[i];
            else rightOdd += nums[i];
        }
        
        int leftEven = 0, leftOdd = 0;
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) rightEven -= nums[i];
            else rightOdd -= nums[i];
             
            if (leftEven + rightOdd == leftOdd + rightEven) res++;
            
            if (i % 2 == 0) leftEven += nums[i];
            else leftOdd += nums[i];
        }
        return res;
    }
}