// https://leetcode.com/problems/number-of-lines-to-write-string/

class Solution {
    public int[] numberOfLines(int[] widths, String s) {
        int numLines = 1; 
        int currLineWidth = 0;
        
        for (char c : s.toCharArray()) {
            if (currLineWidth + widths[c - 'a'] > 100) {
                numLines++;
                currLineWidth = 0;
            }
            currLineWidth += widths[c - 'a'];
        }
        return new int[]{numLines, currLineWidth};
    }
}