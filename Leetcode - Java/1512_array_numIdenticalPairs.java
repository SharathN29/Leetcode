// https://leetcode.com/problems/number-of-good-pairs/

class Solution {
    public int numIdenticalPairs(int[] nums) {
        int res = 0, count[] = new int[101];
        for (int n : nums) {
            res += count[n]++;
        }
        return res; 
    }
}