// https://leetcode.com/problems/detect-capital/

class Solution {
    public boolean detectCapitalUse(String word) {
        int len = word.length();
        if (len == 1) return true;
        
        if (Character.isUpperCase(word.charAt(0)) && Character.isUpperCase(word.charAt(1))) {
            for (int i = 2; i < len; i++) {
                if (Character.isLowerCase(word.charAt(i))) {
                    return false; 
                }
            }
        } else {
            for (int i = 1; i < len; i++) {
                if (Character.isUpperCase(word.charAt(i))) {
                    return false; 
                }
            }
        }
        return true; 
    }
}