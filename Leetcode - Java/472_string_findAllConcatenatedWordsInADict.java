// https://leetcode.com/problems/concatenated-words/

class Solution {
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        Arrays.sort(words, (a, b) -> a.length() - b.length());
        List<String> res = new ArrayList();
        Set<String> preWords = new HashSet();
        
        for (String word : words) {
            if (wordBreak(word, preWords, 0, new Boolean[word.length()])) {
                res.add(word);
            }
            preWords.add(word);
        }
        return res; 
    }
    
    public boolean wordBreak(String s, Set<String> wordDict, int index, Boolean[] memo) {
        if (wordDict.isEmpty()) {
            return false;
        }
        
        if (index == s.length()) {
            return true; 
        }
        
        if (memo[index] != null) {
            return memo[index];
        }
        
        for (int end = index + 1; end <= s.length(); end++) {
            if (wordDict.contains(s.substring(index, end)) && wordBreak(s, wordDict, end, memo)) {
                return memo[index] = true;
            }
        }
        return memo[index] = false;
    }
}