// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
    public int characterReplacement(String s, int k) {
        int i = 0, maxLen = 0, maxRepCount = 0;
        int[] count = new int[26];
        
        for (int j = 0; j < s.length(); j++) {
            maxRepCount = Math.max(maxRepCount, ++count[s.charAt(j) - 'A']);
            
            if (j - i + 1 - maxRepCount > k) {
                count[s.charAt(i++) - 'A']--;
            }
            
            maxLen = Math.max(maxLen, j - i + 1);
        }
        return maxLen;
    }
}