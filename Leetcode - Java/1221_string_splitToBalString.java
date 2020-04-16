// https://leetcode.com/problems/split-a-string-in-balanced-strings/

class Solution {
    public int balancedStringSplit(String s) {
        int count = 0;
        int blocks = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == 'R') blocks++;
            else if(s.charAt(i) == 'L') blocks--;
            
            if(blocks == 0) count++;
        }
        return count;
    }
}