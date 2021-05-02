// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/

class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        Arrays.sort(arr);
        int curr = 1;
        
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > curr) {
                curr++;
            }
        }
        return curr;
    }
}
