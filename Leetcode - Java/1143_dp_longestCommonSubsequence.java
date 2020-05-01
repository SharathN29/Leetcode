// https://leetcode.com/problems/longest-common-subsequence/

class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int[][] dpgrid = new int[text1.length() + 1][text2.length() + 1];
        for(int col = text2.length() - 1; col >= 0; col--) {
            for(int row = text1.length() - 1; row >= 0; row--) {
                if(text1.charAt(row) == text2.charAt(col)) {
                    dpgrid[row][col] = 1 + dpgrid[row+1][col+1];
                } else {
                    dpgrid[row][col] = Math.max(dpgrid[row+1][col], dpgrid[row][col+1]);
                }
            }
        }
        return dpgrid[0][0];
    }
}