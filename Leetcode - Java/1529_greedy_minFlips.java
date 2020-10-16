// https://leetcode.com/problems/bulb-switcher-iv/

class Solution {
    public int minFlips(String target) {
        int flip = 0, state = 0; 
        for (char c : target.toCharArray()) {
            if (c - '0' != state) {
                flip++;
                state = c - '0';
            } 
        }
        return flip;
    }
}