// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

class Solution {
    public boolean checkIfPangram(String sentence) {
        int[] chars = new int[26];
        for (char c : sentence.toCharArray()) {
            chars[c - 'a']++;
        }
        
        for (int i : chars) {
            if (i == 0) return false;
        }
        return true;
    }
}
