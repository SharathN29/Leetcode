// https://leetcode.com/problems/minimum-operations-to-make-array-equal/

class Solution {
    public int minOperations(int n) {
        int mid = n / 2;
        int res = 0;
        int i = 0;
        while (i < mid) {
            res += 2 * (i+1);
            i++;
        }
        i++;
        while (i < n) {
            res += 2 * (i - mid);
            i++;
        }
        return res / 2;
    }
}