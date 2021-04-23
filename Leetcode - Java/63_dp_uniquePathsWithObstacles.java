// https://leetcode.com/problems/unique-paths-ii/

class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int r = obstacleGrid.length, c = obstacleGrid[0].length;
        int[][] dp = new int[r][c];
        
        for (int i = 0; i < r; i++) {
            if (obstacleGrid[i][0] == 1) {
                dp[i][0] = 0;
                break;
            } else {
                dp[i][0] = 1;
            }
        }
        
        for (int j = 0; j < c; j++) {
            if (obstacleGrid[0][j] == 1) {
                dp[0][j] = 0;
                break;
            } else {
                dp[0][j] = 1;
            }
        }
        
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        
        return dp[r-1][c-1];
    }
}