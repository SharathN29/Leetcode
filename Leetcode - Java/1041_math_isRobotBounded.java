// https://leetcode.com/problems/robot-bounded-in-circle/

class Solution {
    public boolean isRobotBounded(String instructions) {
        int[][] directions = new int[][]{{0,1},{1,0},{0,-1},{-1,0}};
        int x = 0, y = 0;
        int index = 0;
        
        for (char c : instructions.toCharArray()) {
            if (c == 'L') {
                index = (index + 3) % 4; 
            } else if (c == 'R') {
                index = (index + 1) % 4;
            } else {
                x += directions[index][0];
                y += directions[index][1];
            }
        }
        
        return (x == 0 && y == 0) || index != 0;
    }
}