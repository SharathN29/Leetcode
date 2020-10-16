// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

class Solution {
    public int countOdds(int low, int high) {
        int res = (high - low) / 2;
        return (low % 2 != 0 || high % 2 != 0) ? res + 1 : res; 
    }
}