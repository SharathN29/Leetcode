// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

class Solution {
    public int findNumbers(int[] nums) {
        int res = 0;
        for(int n : nums) {
            if(Integer.toString(n).length() % 2 == 0) 
                res++;
        }
        return res; 
    }
}