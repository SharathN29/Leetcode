// https://leetcode.com/problems/missing-number-in-arithmetic-progression/

class Solution {
    public int missingNumber(int[] A) {
        int first = A[0], last = A[0], sum = 0, n = A.length;
        for (int a : A) {
            first = Math.min(first, a);
            last = Math.max(last, a);
            sum += a;
        }
        return (first + last) * (n + 1) / 2 - sum;
    }
}