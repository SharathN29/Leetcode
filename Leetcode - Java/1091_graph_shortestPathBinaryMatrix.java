// https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution {
    
    private int[][] dir = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    
    public int shortestPathBinaryMatrix(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return -1; 
        
        boolean[][] visited = new boolean[m][n];
        visited[0][0] = true; 
        Queue<int[]> q = new LinkedList();
        q.add(new int[]{0, 0});
        
        int ans = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int[] top = q.poll();
                if (top[0] == m - 1 && top[1] == n - 1) {
                    return ans + 1;
                }
                
                for (int k = 0; k < 8; k++) {
                    int nextX = dir[k][0] + top[0];
                    int nextY = dir[k][1] + top[1]; 
                    
                    if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && !visited[nextX][nextY] && grid[nextX][nextY] == 0) {
                        q.add(new int[]{nextX, nextY});
                        visited[nextX][nextY] = true;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
}