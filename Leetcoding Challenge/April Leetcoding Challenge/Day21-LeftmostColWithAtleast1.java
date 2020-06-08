// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3306/

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface BinaryMatrix {
 *     public int get(int x, int y) {}
 *     public List<Integer> dimensions {}
 * };
 */

class Solution {
    public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        List<Integer> dimention = binaryMatrix.dimensions();
        int rows = dimention.get(0), columns = dimention.get(1);
        
        if(rows == 0 || columns == 0) return -1;
        
        int left_column = -1;
        int r = 0, c = columns-1;
        
        while(r < rows && c >= 0) {
            if(binaryMatrix.get(r, c) == 1) {
                left_column = c;
                c--;
            } else {
                r++; 
            }
        }
        return left_column;
    }
}