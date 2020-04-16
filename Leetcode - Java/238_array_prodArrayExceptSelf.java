// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int size = nums.length;
        int left = 1, right = 1; 
        int[] res = new int[size];
        Arrays.fill(res, 1);
        
        for(int i = 1; i < size; i++) {
            left *= nums[i-1];
            res[i] *= left;
        }
        
        for(int j = size-2; j >= 0; j--) {
            right *= nums[j+1];
            res[j] *= right;
        }
        
        return res;
    }
}