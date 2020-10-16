// https://leetcode.com/problems/repeated-substring-pattern/

class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int len = s.length();
        for (int i = len / 2; i >= 1; i--) {
            if (len % i == 0) {
                int m = len / i;
                String substr = s.substring(0, i);
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < m; j++) {
                    sb.append(substr);
                }
                if (sb.toString().equals(s)) return true;
            }
        }
        return false; 
    }
}