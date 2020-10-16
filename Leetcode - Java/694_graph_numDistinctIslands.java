// https://leetcode.com/problems/number-of-distinct-islands/

class Solution {
    public int numDistinctIslands(int[][] grid) {
        Set<String> set = new HashSet();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    StringBuilder sb = new StringBuilder();
                    dfs(grid, i, j, i , j, sb);
                    set.add(sb.toString());
                }
            }
        }
        return set.size();
    }
    
    private void dfs(int[][] grid, int i, int j, int r, int c, StringBuilder sb) {
        int m = grid.length, n = grid[0].length;
        if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
            grid[r][c] = 0; 
            sb.append(String.valueOf(r - i) + String.valueOf(c - j));
            dfs(grid, i, j, r-1, c, sb);
            dfs(grid, i, j, r+1, c, sb);
            dfs(grid, i, j, r, c-1, sb);
            dfs(grid, i, j, r, c+1, sb);
        }
    }
}