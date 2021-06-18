// https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/

class Solution {
    public boolean checkZeroOnes(String s) {
        int maxOnes = Integer.MIN_VALUE, maxZeros = Integer.MIN_VALUE;
        int one = 0, zero = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                maxOnes = Math.max(maxOnes, ++one);
                zero = 0;
            } else {
                maxZeros = Math.max(maxZeros, ++zero);
                one = 0;
            }
        }
        return maxOnes > maxZeros;
    }
}