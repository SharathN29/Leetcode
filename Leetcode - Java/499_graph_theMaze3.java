// https://leetcode.com/problems/the-maze-iii/

class Solution {
    private class Point {
        private int row, col, dist;
        private String path;
        Point(int r, int c, int d, String p) {
            row = r;
            col = c;
            dist = d;
            path = p;
        }
    }
    
    public String findShortestWay(int[][] maze, int[] ball, int[] hole) {
        int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        char[] turns = {'d', 'u', 'r', 'l'};
        int m = maze.length, n = maze[0].length;
        boolean[][] marked = new boolean[m][n];
        Queue<Point> q = new PriorityQueue<>((p1, p2) -> p1.dist == p2.dist ? p1.path.compareTo(p2.path) : p1.dist - p2.dist);
        q.add(new Point(ball[0], ball[1], 0, ""));
        
        while (!q.isEmpty()) {
            Point cur = q.poll();
            int row = cur.row, col = cur.col;
            if (row == hole[0] && col == hole[1]) return cur.path;
            if (marked[row][col]) continue;
            marked[row][col] = true;
            for (int i = 0; i < 4; i++) {
                int r = row, c = col, dist = cur.dist;
                while (r >= 0 && r < m && c >= 0 && c < n && maze[r][c] == 0 && (r != hole[0] || c != hole[1])) {
                    r += dirs[i][0];
                    c += dirs[i][1];
                    dist++;
                }
                if (r != hole[0] || c != hole[1]) {
                    r -= dirs[i][0];
                    c -= dirs[i][1];
                    dist--;
                }
                if (!marked[r][c]) {
                    q.add(new Point(r, c, dist, cur.path+turns[i]));
                }
            }
        }
        return "impossible";
    }
}