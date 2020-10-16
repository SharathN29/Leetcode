// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/

class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        int[] countArr = new int[1001];
        for(int i = 0; i < arr.length; i++) {
            countArr[target[i]]++;
            countArr[arr[i]]--;
        }
        
        for(int i = 0; i < countArr.length; i++) {
            if(countArr[i] != 0) 
                return false;
        }
        return true; 
    }
}