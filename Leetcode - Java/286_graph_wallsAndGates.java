// https://leetcode.com/problems/walls-and-gates/

class Pair {
    int x, y;
    
    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
    
    public int getX() {
        return this.x;
    }
    
    public int getY() {
        return this.y;
    }
}

class Solution {
    public void wallsAndGates(int[][] rooms) {
        int rows = rooms.length;
        if (rows == 0) return;
        int cols = rooms[0].length;
        
        Queue<Pair> canReach = new LinkedList();
        int[][] dirs = new int[][]{{1,0},{-1,0},{0,1},{0,-1}};
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (rooms[i][j] == 0) {
                    canReach.add(new Pair(i, j));
                }
            }
        }
        
        while (!canReach.isEmpty()) {
            int r = canReach.peek().getX(), c = canReach.peek().getY();
            canReach.poll();
            
            for (int[] dir : dirs) {
                int x = r + dir[0], y = c + dir[1];
                if (x < 0 || x >= rows || y < 0 || y >= cols || rooms[x][y] <= rooms[r][c] + 1)
                    continue;
                rooms[x][y] = rooms[r][c] + 1;
                canReach.add(new Pair(x,y));
            }
        }
    }
}