// https://leetcode.com/problems/count-the-number-of-consistent-strings/

class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        int numConsistentStrs = words.length;
        Set<Character> allowedChars = new HashSet();
        
        for (char c : allowed.toCharArray()) {
            allowedChars.add(c);
        }
        
        for (String word : words) {
            for (char c : word.toCharArray()) {
                if (!allowedChars.contains(c)) {
                    numConsistentStrs--;
                    break;
                }
            }
        }
        
        return numConsistentStrs;
    }
}
