// https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/

class Solution {
    public int maxNumberOfApples(int[] arr) {
        Arrays.sort(arr);
        int i = 0, weight = 0; 
        for(i=0; i<arr.length && weight + arr[i] <= 5000; i++) {
            weight += arr[i]; 
        }
        return i;
    }
}