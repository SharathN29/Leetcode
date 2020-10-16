// https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/

class Solution {
    public int closestToTarget(int[] arr, int target) {
        int m = arr.length, res = Integer.MAX_VALUE; 
        for (int i = 0; i < m; i++) {
            int sum = arr[i];
            for (int r = i; r < m; r++) {
                sum = sum & arr[r];
                res = Math.min(res, Math.abs(sum - target));
                if (res == 0) return res; 
                if (sum <= target) break;
            }
            if (sum > target) break;
        }
        return res;
    }
}