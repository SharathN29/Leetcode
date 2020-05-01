// https://leetcode.com/problems/lonely-pixel-i/

class Solution {
    public int findLonelyPixel(char[][] picture) {
        int rows = picture.length, cols = picture[0].length; 
        int[] rowCount = new int[rows], colCount = new int[cols];
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(picture[i][j] == 'B') {
                    rowCount[i]++;
                    colCount[j]++; 
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(picture[i][j] == 'B' && rowCount[i] == 1 && colCount[j] == 1) {
                    count++;
                }
            }
        }
        
        return count; 
    }
}