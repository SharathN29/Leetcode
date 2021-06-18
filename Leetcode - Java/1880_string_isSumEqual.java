// https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/

class Solution {
    public boolean isSumEqual(String firstWord, String secondWord, String targetWord) {
        return getIntValue(firstWord) + getIntValue(secondWord) == getIntValue(targetWord);
    }
    
    private int getIntValue(String s) {
        int result = 0;
        for (char c : s.toCharArray()) {
            result = result * 10 + (c - 'a');
        } 
        return result;
    }
}