// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
    public int[] sortedSquares(int[] A) {
        int left = 0, right = A.length-1;
        int[] res = new int[A.length];
        
        for(int i = A.length-1; i >=0; i--) {
            if(Math.abs(A[left]) > Math.abs(A[right])) {
                res[i] = A[left] * A[left];
                left++;
            } else {
                res[i] = A[right] * A[right];
                right--;
            }
        }
        return res;
    }
}