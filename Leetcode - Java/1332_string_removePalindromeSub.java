// https://leetcode.com/problems/remove-palindromic-subsequences/

class Solution {
    public int removePalindromeSub(String s) {
        if (s.isEmpty()) return 0;
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        String reversedString = sb.toString();
        return reversedString.equals(s) ? 1 : 2;
    }
}
