// https://leetcode.com/problems/max-consecutive-ones-ii/

class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int pre = 0, curr = 0, result = 0;
        for(int n : nums) {
            if(n  == 1) {
                curr++;
            } else {
                pre = curr + 1;
                curr = 0;
            }
            result = Math.max(result, pre + curr);
        }
        return result; 
    }
}