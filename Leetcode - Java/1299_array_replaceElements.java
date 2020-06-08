// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

class Solution {
    public int[] replaceElements(int[] arr) {
        int size = arr.length-1;
        int prevElem = arr[size];
        arr[size] = -1; 
        for(int i = size - 1; i >= 0; i--) {
            int currElem = Math.max(prevElem, arr[i+1]);
            prevElem = arr[i];
            arr[i] = currElem;
        }
        return arr;
    }
}