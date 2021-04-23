// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

class Solution {
    public String findLongestWord(String s, List<String> d) {
        String maxstr = "";
        for (String str : d) {
            if (isSubsequence(str, s)) {
                if (str.length() > maxstr.length() || (str.length() == maxstr.length() && str.compareTo(maxstr) < 0)) {
                    maxstr = str;
                }
            }
        }
        return maxstr;
    }

    private boolean isSubsequence(String x, String y) {
        int j = 0;
        for (int i = 0; i < y.length() && j < x.length(); i++) {
            if (x.charAt(j) == y.charAt(i)) {
                j++;
            }
        }
        return j == x.length();
    }
}
