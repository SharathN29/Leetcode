// https://leetcode.com/problems/path-with-maximum-minimum-value/

class Solution {
    public int maximumMinimumPath(int[][] A) {
        int m = A.length, n = A[0].length;
        int[][] direction = new int[][]{{1,0},{0,1},{-1,0},{0,-1}};
        boolean[][] visited = new boolean[m][n];
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> b[2] - a[2]);
        pq.offer(new int[]{0, 0, A[0][0]});

        while (!pq.isEmpty()) {
            int[] cell = pq.poll();
            int row = cell[0], col = cell[1];
            if (row == m - 1 && col == n - 1) {
                return cell[2];
            }
            visited[row][col] = true;

            for (int[] dir : direction) {
                int nextRow = dir[0] + row, nextCol = dir[1] + col;
                if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n || visited[nextRow][nextCol]) {
                    continue;
                }
                pq.offer(new int[]{nextRow, nextCol, Math.min(cell[2], A[nextRow][nextCol])});
            }
        }
        return -1;
    }
}
