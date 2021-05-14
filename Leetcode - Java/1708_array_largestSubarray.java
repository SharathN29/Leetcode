// https://leetcode.com/problems/largest-subarray-length-k/

class Solution {
    public int[] largestSubarray(int[] nums, int k) {
        int largestElem = Integer.MIN_VALUE, largestElemIndex = -1;
        
        for (int i = 0; i < nums.length - k + 1; i++) {
            if (nums[i] > largestElem) {
                largestElem = nums[i];
                largestElemIndex = i;
            }
        }
        int[] res = new int[k];
        
        for (int i = largestElemIndex, j = 0; i < largestElemIndex + k; i++, j++) {
            res[j] = nums[i];
        }
        
        return res;
    }
}