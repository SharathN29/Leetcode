// https://leetcode.com/problems/decompress-run-length-encoded-list/

class Solution {
    public int[] decompressRLElist(int[] nums) {
        List<Integer> res = new ArrayList<Integer>();
        for(int i = 0; i < nums.length/2; i++) {
            int freq = nums[2*i];
            int val = nums[2*i+1];
            while(freq > 0) {
                res.add(val);
                freq--;
            }
        }
         int[] result = new int[res.size()];
        for(int i = 0; i < res.size(); i++) {
            result[i] = res.get(i).intValue();
        }
        return result; 
    }
}