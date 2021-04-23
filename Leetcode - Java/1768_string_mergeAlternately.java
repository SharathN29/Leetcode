// https://leetcode.com/problems/merge-strings-alternately/

class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder sb = new StringBuilder();
        int i;
        for (i = 0; i < Math.min(word1.length(), word2.length()); i++) {
            sb.append(word1.charAt(i));
            sb.append(word2.charAt(i));
        }
        
        if (i == word1.length()) sb.append(word2.substring(i));
        else sb.append(word1.substring(i));
        
        return sb.toString();
    }
}