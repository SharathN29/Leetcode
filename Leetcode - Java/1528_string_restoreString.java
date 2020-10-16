// https://leetcode.com/problems/shuffle-string/

class Solution {
    public String restoreString(String s, int[] indices) {
        int n = s.length();
        char[] a = new char[n];
        for (int i = 0; i < s.length(); ++i) {
            a[indices[i]] =  s.charAt(i);
        }
        return String.valueOf(a);
    }
}