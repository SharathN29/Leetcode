// https://leetcode.com/problems/decoded-string-at-index/

class Solution {
    public String decodeAtIndex(String S, int K) {
        long currentLength = 0;
        char c = 0;
        
        for (int i = 0; i < S.length(); i++) {
            c = S.charAt(i);
            if (Character.isDigit(c)) {
                currentLength *= c - '0';
            } else {
                currentLength++;
            }
        }
        
        for (int i = S.length() - 1; i >= 0; i--) {
            c = S.charAt(i);
            if (Character.isDigit(c)) {
                currentLength /= c - '0';
                K %= currentLength; 
            } else {
                if (K == 0 || K == currentLength) {
                    return "" + c;
                }
                currentLength--;
            }
        }
        
        throw null;
    }
}