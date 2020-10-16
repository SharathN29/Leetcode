// https://leetcode.com/problems/path-crossing/

class Solution {
    public boolean isPathCrossing(String path) {
        Set<String> coordinates = new HashSet();
        coordinates.add("(0,0)");
        int x = 0, y = 0;
        for (int i = 0; i < path.length(); i++) {
            if (path.charAt(i) == 'N') y++;
            else if (path.charAt(i) == 'S') y--;
            else if (path.charAt(i) == 'E') x++;
            else if (path.charAt(i) == 'W') x--;
            
            String s = "(" + x + "," + y + ")";
            if (coordinates.contains(s)) return true; 
            else coordinates.add(s);
        }
        return false;
    }
}