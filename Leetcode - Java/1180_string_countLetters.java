// https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/

class Solution {
    public int countLetters(String S) {
        int res = 0, repeat = 1;
        for (int i = 1; i < S.length(); i++, ++repeat) {
            if (S.charAt(i) != S.charAt(i - 1)) {
                res += repeat * (repeat + 1) / 2;
                repeat = 0;
            }
        }
        return res + repeat * (repeat + 1) / 2;
    }
}