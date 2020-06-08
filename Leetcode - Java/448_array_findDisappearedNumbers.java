// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        for(int i = 0; i < nums.length; i++) {
            int idx = Math.abs(nums[i]);
            nums[idx-1] = -(Math.abs(nums[idx-1]));
        }
        List<Integer> res = new ArrayList<Integer>(); 
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] > 0) {
                res.add(i+1);
            }
        }
        return res; 
    }
}