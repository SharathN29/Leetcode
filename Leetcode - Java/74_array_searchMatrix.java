// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0) return false; 
        int row = matrix.length, col = matrix[0].length;
        int left = 0, right = row * col - 1;
        
        while (left <= right) {
            int pivotIdx = (left + right) / 2;
            int pivotElem = matrix[pivotIdx / col][pivotIdx % col];
            if (target == pivotElem) return true;
            else if (target < pivotElem) right = pivotIdx - 1;
            else left = pivotIdx + 1;
        }
        return false;
    }
}