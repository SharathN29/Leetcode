// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

class Solution {
    public int minOperations(int[] nums, int x) {
        // so we take out elements from left and right end such that x reduces to 0.
        // we must maximise the length of the subarray whose sum = totalsum - x

        int total = -x;
        for (int n : nums) {
            total += n;
        }

        if (total == 0) return nums.length;

        Map<Integer, Integer> map = new HashMap();
        map.put(0, -1);
        int sum = 0, res = Integer.MIN_VALUE;

        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (map.containsKey(sum - total)) {
                res = Math.max(res, i - map.get(sum - total));
            }
            map.put(sum, i);
        }
        return res == Integer.MIN_VALUE ? -1 : nums.length - res;
    }
}
