// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3368/

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