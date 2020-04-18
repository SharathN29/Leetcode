// https://leetcode.com/problems/island-perimeter/

class Solution {
    public int islandPerimeter(int[][] grid) {
        int m = grid.length;
        if(m == 0) return 0;
        int n = grid[0].length;
        int[][] dir = {{0,-1},{0,1},{-1,0},{1,0}};
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    return helper(grid, dir, i, j);
                }
            }
        }
        return 0;
    }
    
    private int helper(int[][] grid, int[][] dir, int i, int j) {
        int m = grid.length, n = grid[0].length;
        grid[i][j] = -1;
        int count = 0;
        
        for(int[] d : dir) {
            int x = i + d[0], y = j + d[1];
            if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0) {
                count++;
            } else {
                if(grid[x][y] == 1) {
                    count += helper(grid, dir, x, y);
                }
            }
        }
        return count;
    }
}