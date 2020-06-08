// https://leetcode.com/problems/duplicate-zeros/

class Solution {
    public void duplicateZeros(int[] arr) {
        int length = arr.length-1, duplicates = 0; 
        for(int left = 0; left <= length - duplicates; left++) {
            if(arr[left] == 0) {
                if(left == length - duplicates) {
                    arr[length] = 0;
                    length--;
                    break;
                }
                duplicates++;
            }
        }
        
        int last = length - duplicates; 
        for(int i = last; i >= 0; i--) {
            if(arr[i] == 0) {
                arr[i + duplicates] = 0;
                duplicates--;
                arr[i + duplicates] = 0;
            } else {
                arr[i + duplicates] = arr[i];
            }
        }
    }
}