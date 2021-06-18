// https://leetcode.com/problems/find-a-peak-element-ii/

class Solution {
    public int[] findPeakGrid(int[][] mat) {
        int left = 0, right = mat[0].length - 1; 
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int maxRow = 0;
            for (int i = 0; i < mat.length; i++) {
                maxRow = mat[i][mid] > mat[maxRow][mid] ? i : maxRow;
            }
            boolean isLeftBig = mid - 1 >= left && mat[maxRow][mid - 1] > mat[maxRow][mid];
            boolean isRightBig = mid + 1 <= right && mat[maxRow][mid + 1] > mat[maxRow][mid];
            
            if (!isLeftBig && !isRightBig) {
                return new int[]{maxRow, mid};
            } else if (isRightBig) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return null;
    }
}