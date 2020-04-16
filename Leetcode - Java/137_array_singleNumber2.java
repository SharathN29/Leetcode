// https://leetcode.com/problems/single-number-ii/

class Solution {
    public int singleNumber(int[] nums) {
        int seenOnce = 0, seenTwice = 0;
        for(int n : nums) {
            seenOnce = ~seenTwice & (seenOnce ^ n);
            seenTwice = ~seenOnce & (seenTwice ^ n);
        }
        return seenOnce;
    }
}