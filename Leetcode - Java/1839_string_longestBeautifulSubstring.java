// https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/

class Solution {
    public int longestBeautifulSubstring(String word) {
        int maxLen = 0;
        if (word == null || word.length() == 0) return maxLen;
        
        Set<Character> seen = new HashSet<>();
        
        for (int i = -1, j = 0; j < word.length(); j++) {
            if (j > 0 && word.charAt(j - 1) > word.charAt(j)) {
                seen = new HashSet<>();
                i = j - 1;
            }
            seen.add(word.charAt(j));
            if (seen.size() == 5) {
                maxLen = Math.max(maxLen, j - i);
            }
        }
        
        return maxLen;
    }
}
