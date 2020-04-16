// https://leetcode.com/problems/implement-strstr/

class Solution {
    public int strStr(String haystack, String needle) {
        int l = needle.length(), n = haystack.length();
        for(int start = 0; start < n-l+1; start++) {
            if(haystack.substring(start, start+l).equals(needle)) {
                return start;
            }
        }
        return -1;
    }
}