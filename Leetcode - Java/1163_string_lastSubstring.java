// https://leetcode.com/problems/last-substring-in-lexicographical-order/

class Solution {
    public String lastSubstring(String s) {
        int i = 0, j = 1, k = 0, n = s.length();
        while (j + k < n) {
            if (s.charAt(i + k) == s.charAt(j + k)) k++;
            else if (s.charAt(i + k) < s.charAt(j + k)) {
                i = j;
                j++;
                k = 0;
            } else if (s.charAt(i + k) > s.charAt(j + k)) {
                j = j + k + 1;
                k = 0;
            }
        }
        return s.substring(i);
    }
}
