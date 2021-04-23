// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

class Solution {
    public int minimumDeletions(String s) {
        int a = 0, b = 0;
        for (char c : s.toCharArray()) {
            if (c == 'a') a++;
            else a = Math.min(a, b++);
        }
        return Math.min(a, b);
    }
}
