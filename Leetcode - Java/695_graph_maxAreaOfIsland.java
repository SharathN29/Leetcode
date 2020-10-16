// https://leetcode.com/problems/max-area-of-island/

class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int nr = grid.length;
        if (nr == 0) return 0;
        int nc = grid[0].length;
        boolean[][] seen = new boolean[nr][nc];
        int maxArea = 0;
        
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                maxArea = Math.max(maxArea, area(i, j, grid, seen));
            }
        }
        
        return maxArea;
    }
    
    private int area(int r, int c, int[][] grid, boolean[][] seen) {
        if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length || seen[r][c] || grid[r][c]  == 0)
            return 0;
        
        seen[r][c] = true;
        
        return 1 + area(r-1, c, grid, seen) + area(r+1, c, grid, seen) + 
                   area(r, c-1, grid, seen) + area(r, c+1, grid, seen);
    }
}