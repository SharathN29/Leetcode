// https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
    public boolean increasingTriplet(int[] nums) {
        int c1 = Integer.MAX_VALUE, c2 = Integer.MAX_VALUE;
        
        for (int n : nums) {
            if (n <= c1) {
                c1 = n;
            } else if (n <= c2) {
                c2 = n;
            } else return true;
        }
        return false;
    }
}