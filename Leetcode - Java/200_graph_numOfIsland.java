// https://leetcode.com/problems/number-of-islands/

class Solution {
    public int numIslands(char[][] grid) {
        int nr = grid.length;
        if(nr == 0) return 0;
        int nc = grid[0].length; 
        
        int num_of_island = 0;
        for(int i = 0; i < nr; i++) {
            for(int j = 0; j < nc; j++) {
                if(grid[i][j] == '1') {
                    num_of_island++;
                    dfs(grid, i, j);
                } 
            }
        }
        return num_of_island;
    }
    
    private void dfs(char[][] grid, int r, int c) {
        int nr = grid.length, nc = grid[0].length;
        grid[r][c] = '0';
        
        if(r-1 >= 0 && grid[r-1][c] == '1') dfs(grid, r-1, c);
        if(r+1 < nr && grid[r+1][c] == '1') dfs(grid, r+1, c);
        if(c-1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c-1);
        if(c+1 < nc && grid[r][c+1] == '1') dfs(grid, r, c+1);
    }
}