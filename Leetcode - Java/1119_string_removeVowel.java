// https://leetcode.com/problems/remove-vowels-from-a-string/

class Solution {
    public String removeVowels(String S) {
        StringBuffer sb = new StringBuffer(S.length());
        for(int i = 0; i < S.length(); i++) {
            if(!isVowel(S.charAt(i))) {
                sb.append(S.charAt(i));
            }
        }
        return sb.toString();
    }
    
    private boolean isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false; 
    }
}