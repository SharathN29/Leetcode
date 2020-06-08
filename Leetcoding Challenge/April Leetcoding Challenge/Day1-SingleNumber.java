// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3283/

class Solution {
    public int singleNumber(int[] nums) {
        int res = 0;
        for(int n : nums) 
            res ^= n;
        
        return res; 
    }
}