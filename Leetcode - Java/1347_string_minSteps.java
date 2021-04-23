// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

class Solution {
    public int minSteps(String s, String t) {
        int[] count = new int[26];
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
            count[t.charAt(i) - 'a']--;
        }
        int diff = 0;
        for (int i = 0; i < 26; i++) {
            diff += Math.abs(count[i]);
        }

        return diff / 2;
    }
}
