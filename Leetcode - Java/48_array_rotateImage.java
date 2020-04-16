// https://leetcode.com/problems/rotate-image/

class Solution {
    public void rotate(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        for(int i = 0; i < m; i++) {
            for(int j = i; j < n; j++) {
                int temp = 0;
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m/2; j++){
                int temp = 0;
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][m-1-j];
                matrix[i][m-1-j] = temp;
            }
        }
    }
}