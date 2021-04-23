// https://leetcode.com/problems/projection-area-of-3d-shapes/

class Solution {
    public int projectionArea(int[][] grid) {
        int n = grid.length;
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            int row = 0, col = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) res++;
                row = Math.max(grid[i][j], row);
                col = Math.max(grid[j][i], col);
            }
            res += row + col;
        }
        return res;
    }
}