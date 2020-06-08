// https://leetcode.com/problems/power-of-two/

class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n == 0) return false; 
        long x = (long) n;
        return (x & (-x)) == x;
    }
}

// Time : O(1), Space : O(1)