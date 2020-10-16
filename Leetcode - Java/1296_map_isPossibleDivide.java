// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        if (nums.length % k != 0) {
            return false; 
        }
        
        TreeMap<Integer, Integer> count = new TreeMap();
        for (int num : nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }
        
        while (count.size() > 0) {
            int minval = count.firstKey();
            for (int i = minval; i < minval + k; i++) {
                if (!count.containsKey(i)) return false; 
                count.put(i, count.get(i) - 1);
                if (count.get(i) == 0) {
                    count.remove(i);
                }
            } 
        }
        return true; 
    }
}