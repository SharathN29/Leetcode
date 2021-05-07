// https://leetcode.com/problems/truncate-sentence/

class Solution {
    public String truncateSentence(String s, int k) {
        String[] words = s.split(" ");
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < k; i++) {
            sb.append(words[i]);
            sb.append(' ');
        }
        
        sb.deleteCharAt(sb.length() - 1);
        
        return sb.toString();
    }
}
