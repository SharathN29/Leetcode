// https://leetcode.com/problems/two-sum-less-than-k/

class Solution {
    public int twoSumLessThanK(int[] A, int K) {
        int sum = -1;
        Arrays.sort(A);
        int low = 0, high = A.length - 1;
        while (low < high) {
            if (A[low] + A[high] < K) {
                sum = Math.max(sum, A[low] + A[high]);
                low++;
            } else {
                --high;
            }
        }
        return sum;
    }
}