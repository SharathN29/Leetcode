// https://leetcode.com/problems/path-with-maximum-gold/

class Solution {
    public int getMaximumGold(int[][] grid) {
        int m = grid.length, n = grid[0].length; 
        int maxGold = 0; 
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                maxGold = Math.max(maxGold, findMaxGold(grid, m, n, r, c));
            }
        }
        
        return maxGold;
    }
    
    int[] dir = new int[]{0, 1, 0, -1, 0};
    
    public int findMaxGold(int[][] grid, int m, int n, int r, int c) {
        if (r < 0 || r == m || c < 0 || c == n || grid[r][c] == 0) {
            return 0;
        }
        int origin = grid[r][c];
        grid[r][c] = 0;
        int maxGold = 0;
        for (int i = 0; i < 4; i++) {
            maxGold = Math.max(maxGold, findMaxGold(grid, m, n, r + dir[i], c + dir[i+1]));
        }
        grid[r][c] = origin;
        return maxGold + origin;
    }
}