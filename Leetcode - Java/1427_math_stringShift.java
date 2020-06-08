// https://leetcode.com/problems/perform-string-shifts/

class Solution {
    public String stringShift(String s, int[][] shift) {
        int rotate = 0;
        for(int[] sh : shift) {
            if(sh[0] == 0) rotate += sh[1];
            else if(sh[0] == 1) rotate -= sh[1];
        }  
        if(rotate == 0) return s;
        else if(rotate < 0) return rightrotate(s, Math.abs(rotate%s.length()));
        else return leftrotate(s, rotate%s.length());
    }
    
    private String leftrotate(String str, int d) {
        return str.substring(d) + str.substring(0,d);
    }
    
    private String rightrotate(String str, int d) {
        return leftrotate(str, str.length()-d);
    }
}