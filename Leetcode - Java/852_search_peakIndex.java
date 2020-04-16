// https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
    public int peakIndexInMountainArray(int[] A) {
        if(A.length == 0) return -1;
        int low = 0, high = A.length-1;
        while(low < high) {
            int mid = low+(high-low)/2;
            if(A[mid] < A[mid+1]) low = mid+1;
            else high = mid;
        }
        return low;
    }
}
