// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int[][] mat = new int[rowSum.length][colSum.length];
        for (int i = 0; i < rowSum.length; i++) {
            for (int j = 0; j < colSum.length; j++) {
                mat[i][j] = Math.min(rowSum[i], colSum[j]);
                rowSum[i] -= mat[i][j];
                colSum[j] -= mat[i][j];
            }
        }
        return mat;
    }
}