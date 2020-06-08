// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/

class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = 0;
        for(int num : nums) {
            n ^= num;
        }
        return n;
    }
}