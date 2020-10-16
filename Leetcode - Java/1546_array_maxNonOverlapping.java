// https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/

class Solution {
    public int maxNonOverlapping(int[] nums, int target) {
        int runningSum = 0, res = 0;
        Set<Integer> set = new HashSet();
        set.add(0);
        
        for (int i = 0; i < nums.length; i++) {
            runningSum += nums[i];
            if (set.contains(runningSum - target)) {
                set.clear();
                runningSum = 0;
                res++;
            }
            set.add(runningSum);
        }
        return res;
    }
}