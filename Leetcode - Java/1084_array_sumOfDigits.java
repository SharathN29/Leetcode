// https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/

class Solution {
    public int sumOfDigits(int[] A) {
        int min = Integer.MAX_VALUE;
        for (int a : A) {
            min = Math.min(min, a);
        }
        
        int sumOfDigits = 0; 
        while (min >= 1) {
            sumOfDigits += min % 10;
            min /= 10;
        }
        
        return (sumOfDigits % 2 == 0) ? 1 : 0;
    }
}