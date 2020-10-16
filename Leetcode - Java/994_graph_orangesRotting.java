// https://leetcode.com/problems/rotting-oranges/

class Solution {
    public int orangesRotting(int[][] grid) {
        int row = grid.length, col = grid[0].length;
        int count_fresh = 0, result = -1; 
        Queue<int[]> q = new LinkedList();
        int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.offer(new int[]{i, j});
                } else if (grid[i][j] == 1) {
                    count_fresh++;
                }
            }
        }
        
        if (count_fresh == 0) return 0;
        
        while (!q.isEmpty()) {
            result++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int[] point = q.poll();
                for (int[] dir : dirs) {
                    int x = point[0] + dir[0], y = point[1] + dir[1];
                    if (x < 0 || y < 0 || x >= row || y >= col || grid[x][y] == 0 || grid[x][y] == 2) {
                        continue;
                    }
                    grid[x][y] = 2;
                    q.offer(new int[]{x, y});
                    count_fresh--;
                }
            }
        }
        return count_fresh == 0 ? result : -1;
    }
}