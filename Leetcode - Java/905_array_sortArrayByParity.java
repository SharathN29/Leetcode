// https://leetcode.com/problems/sort-array-by-parity/

class Solution {
    public int[] sortArrayByParity(int[] A) {
        int left = 0, right = A.length-1; 
        
        while(left < right) {
            if(A[left]%2 > A[right]%2) {
                int temp = A[left];
                A[left] = A[right];
                A[right] = temp; 
            }
            
            if(A[left]%2 == 0) left++;
            if(A[right]%2 == 1) right--;
        }
        return A;
    }
}