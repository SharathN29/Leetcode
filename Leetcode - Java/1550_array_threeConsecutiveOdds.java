// https://leetcode.com/problems/three-consecutive-odds/

class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        if (arr.length < 3) return false;
        int count = 0;
        if (arr[0] % 2 != 0) count++;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] % 2 != 0 && count > 0) {
                count++;
                if (count == 3) return true;
            } else if (arr[i] % 2 != 0) {
                count++;
            } else {
                count = 0;
            }
        }
        return false; 
    }
}