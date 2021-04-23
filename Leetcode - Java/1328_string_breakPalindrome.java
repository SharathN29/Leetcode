// https://leetcode.com/problems/break-a-palindrome/

class Solution {
    public String breakPalindrome(String palindrome) {
        char[] s = palindrome.toCharArray();
        int len = s.length;
        
        for (int i = 0; i < len / 2; i++) {
            if (s[i] != 'a') {
                s[i] = 'a';
                return String.valueOf(s);
            }
        }
        
        s[len - 1] = 'b';
        return len < 2 ? "" : String.valueOf(s);
    } 
}