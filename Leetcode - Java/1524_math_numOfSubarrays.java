// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

class Solution {
    public int numOfSubarrays(int[] arr) {
        int[] count = {1, 0};
        int cur = 0, res = 0, mod = (int)1e9 + 7;
        for (int a : arr) {
            cur ^= a & 1;
            res = (res + count[1 - cur]) % mod;
            count[cur]++;
        }
        return res;
    }
}