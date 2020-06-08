// https://leetcode.com/problems/third-maximum-number/

class Solution {
    public int thirdMax(int[] nums) {
        Set<Integer> maximums = new HashSet<Integer>(); 
        for(int n : nums) {
            maximums.add(n);
            if(maximums.size() > 3) {
                maximums.remove(Collections.min(maximums));
            }
        }
        if(maximums.size() == 3) 
            return Collections.min(maximums);
        return Collections.max(maximums);
    }
}