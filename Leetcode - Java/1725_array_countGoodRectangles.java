// https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/

class Solution {
    public int countGoodRectangles(int[][] rectangles) {
        int[] squareLength = new int[rectangles.length];
        int lenMaxSquare = Integer.MIN_VALUE;
        int countMaxSquare = 0;
        
        for (int i = 0; i < rectangles.length; i++) {
            squareLength[i] = Math.min(rectangles[i][0], rectangles[i][1]);
            lenMaxSquare = Math.max(lenMaxSquare, squareLength[i]);
        }
        
        for (int len : squareLength) {
            if (len == lenMaxSquare) countMaxSquare++;
        }
        
        return countMaxSquare;
    }
}
