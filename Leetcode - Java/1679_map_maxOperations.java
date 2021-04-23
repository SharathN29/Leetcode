// https://leetcode.com/problems/max-number-of-k-sum-pairs/

class Solution {
    public int maxOperations(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap();
        for (int n : nums) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }
        
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            int current = nums[i];
            int complement = k - nums[i];
            if (map.getOrDefault(current, 0) > 0 && map.getOrDefault(complement, 0) > 0) {
                if ((current == complement) && map.get(current) < 2)
                    continue;
                map.put(current, map.get(current) - 1);
                map.put(complement, map.get(complement) - 1);
                count++;
            }
        }
        return count;
    }
}