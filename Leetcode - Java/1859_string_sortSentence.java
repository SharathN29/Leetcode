// https://leetcode.com/problems/sorting-the-sentence/

class Solution {
    public String sortSentence(String s) {
        String[] words = s.split(" ");
        String[] result = new String[words.length];
        
        for (String word : words) {
            int index = Integer.parseInt(word.substring(word.length() - 1));
            result[index - 1] = word.substring(0, word.length() - 1);
        }
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < result.length; i++) {
            sb.append(result[i]);
            sb.append(' ');
        }
        return sb.substring(0, sb.length() - 1).toString();
        
    }
}