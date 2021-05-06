// https://leetcode.com/problems/summary-ranges/

class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> ranges = new ArrayList<>();
        if (nums == null || nums.length == 0) return ranges;
        if (nums.length == 1) {
            ranges.add(nums[0] + "");
            return ranges;
        }
        
        for (int i = 0; i < nums.length; i++) {
            int curr = nums[i];
            while (i + 1 < nums.length && nums[i+1] == nums[i] + 1) {
                i++;
            }
            if (curr != nums[i] ) {
                ranges.add(curr + "->" + nums[i]);
            } else {
                ranges.add(curr + "");
            }
        }
        return ranges;
    }
}
