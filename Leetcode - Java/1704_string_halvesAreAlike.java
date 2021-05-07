// https://leetcode.com/problems/determine-if-string-halves-are-alike/

class Solution {
    public boolean halvesAreAlike(String s) {
        Set<Character> vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
        int vowels1 = 0, vowels2 = 0;
        
        for (int i = 0, j = s.length() / 2; i < s.length() / 2 && j < s.length(); i++, j++) {
            if (vowels.contains(s.charAt(i))) vowels1++;
            if (vowels.contains(s.charAt(j))) vowels2++;
        }
        
        return vowels1 == vowels2;
    }
}
