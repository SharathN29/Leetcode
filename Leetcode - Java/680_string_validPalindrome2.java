// https://leetcode.com/problems/valid-palindrome-ii/

class Solution {
    public boolean validPalindrome(String s) {
        for(int i = 0, j = s.length()-1; i < j; i++, j--) {
            if(s.charAt(i) != s.charAt(j)) return isp(s, i+1, j) || isp(s, i, j-1);
        }
        return true;
    }
    
    private boolean isp(String s, int l, int r) {
        for(int i = l, j = r; i < j; i++, j--) {
            if(s.charAt(i) != s.charAt(j)) return false; 
        }
        return true; 
    }
}