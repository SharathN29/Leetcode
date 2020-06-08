// https://leetcode.com/problems/contiguous-array/

class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int max_length = 0, count = 0;
        
        for(int i = 0; i < nums.length; i++) {
            count += (nums[i] == 1) ? 1 : -1; 
            if(count == 0)
                max_length = Math.max(max_length, i+1);
            if(map.containsKey(count)) {
                max_length = Math.max(max_length, i - map.get(count));
            } else {
                map.put(count, i);
            }
        }
        return max_length;
    }
}