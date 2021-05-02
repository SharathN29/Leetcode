// https://leetcode.com/problems/replace-all-digits-with-characters/

class Solution {
    public String replaceDigits(String s) {
        if (s == null || s.length() == 0) return s;
        StringBuilder sb = new StringBuilder();
        
        for (int index = 0; index < s.length(); index++) {
            if (index % 2 == 0) {
                sb.append(s.charAt(index));
            } else {
                char replacementChar = findReplacementChar(s.charAt(index - 1), s.charAt(index) - '0');
                sb.append(replacementChar);
            }
        }
        return sb.toString();
    }
    
    private char findReplacementChar(char prevChar, int replacementIndex) {
        int newCharAscii = (int)prevChar + replacementIndex;
        if (newCharAscii > 122) {
            newCharAscii = 97 + (newCharAscii - 122);
        }
        return (char)newCharAscii;
    }
}
