// https://leetcode.com/problems/to-lower-case/

class Solution {
    public String toLowerCase(String str) {
        StringBuilder sb = new StringBuilder(); 
        for(char c : str.toCharArray()) {
            sb.append(isUpper(c) ? toLower(c) : c);
        }
        return sb.toString();
    }
    
    private boolean isUpper(char c) {
        return 'A' <= c && c <= 'Z';
    }
    
    private char toLower(char c) {
        return (char) (c - 'A' + 'a');
    }
}