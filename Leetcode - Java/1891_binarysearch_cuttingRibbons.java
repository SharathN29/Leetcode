// https://leetcode.com/problems/cutting-ribbons/

class Solution {
    public int maxLength(int[] ribbons, int k) {
        int l = 1, r = Integer.MAX_VALUE;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (!cutPossible(ribbons, mid, k)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l - 1;
    }
    
    private boolean cutPossible(int[] ribbons, int length, int k) {
        int count = 0;
        for (int ribbon : ribbons) {
            count += (ribbon / length);
        }
        return count >= k;
    }
}