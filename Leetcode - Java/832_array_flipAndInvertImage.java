// https://leetcode.com/problems/flipping-an-image/

class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int col = A[0].length;
        for (int[] row : A) {
            for (int i = 0; i < (col + 1) / 2; i++) {
                int temp = row[i] ^ 1;
                row[i] = row[col - i - 1] ^ 1;
                row[col - i - 1] = temp;
            }
        }
        return A;
    }
}