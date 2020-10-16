// https://leetcode.com/problems/number-of-substrings-with-only-1s/

class Solution {
    public int numSub(String s) {
        int result = 0, count = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                count = count + 1;
            } else {
                count = 0;
            }
            
            result = (result + count) % ((int)1e9 + 7);
        }
        
        return result;
    }
}