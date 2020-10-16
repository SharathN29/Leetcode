// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

class Solution {
    public String freqAlphabets(String s) {
        StringBuilder sb = new StringBuilder();
        int size = s.length();
        for (int i = 0; i < size; i++){
            if (i + 2 < size && s.charAt(i + 2) == '#'){
                sb.append((char) ((Integer.parseInt(s.substring(i, i + 2)) - 1)+ 'a') );
                i = i + 2;
            }
            else {
                sb.append( (char) ( (Integer.parseInt(String.valueOf(s.charAt(i))) - 1) + 'a') ); 
            }
        }
        return sb.toString();
    }
}