// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3308/

class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        while (m < n) 
            n = n & (n - 1);
        return m & n;
    }
}