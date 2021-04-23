// https://leetcode.com/problems/word-break-ii/

class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        return wordBreakHelper(s, wordDict, new HashMap<String, List<String>>());
    }
    
    public List<String> wordBreakHelper(String s, List<String> wordDict, Map<String, List<String>> memo) {
        if (memo.containsKey(s)) {
            return memo.get(s);
        }
        
        List<String> results = new ArrayList();
        if (s == null || s.length() == 0) {
            results.add("");
            return results; 
        }
        
        for (String word : wordDict) {
            if (s.startsWith(word)) {
                String sub = s.substring(word.length());
                List<String> substrings = wordBreakHelper(sub, wordDict, memo);
                
                for (String substring : substrings) {
                    String optionalspace = substring.isEmpty() ? "" : " ";
                    results.add(word + optionalspace + substring);
                }
            }
        }
        
        memo.put(s, results);
        
        return results;
    }
}