// https://leetcode.com/problems/increasing-decreasing-string/

class Solution {
    public String sortString(String s) {
        int n = s.length(), cnt[] = new int[26];
        for (char c : s.toCharArray()) cnt[c - 'a']++;
        StringBuilder sb = new StringBuilder();
        while (n > 0) {
            for (int i = 0; i < 26 && n > 0; i++) {
                if (cnt[i] > 0) {
                    cnt[i]--;
                    sb.append((char) ('a' + i));
                    n--;
                }
            }
            for (int i = 25; i >= 0 && n > 0; i--) {
                if (cnt[i] > 0) {
                    cnt[i]--;
                    sb.append((char) ('a' + i));
                    n--;
                }
            }
        }
        return sb.toString();
    }

}