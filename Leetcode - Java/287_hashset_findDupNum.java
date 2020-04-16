// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
    public int findDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<Integer>();
        for(int n : nums) {
            if(set.contains(n)) return n;
            else set.add(n);
        }
        return -1;
    }
}