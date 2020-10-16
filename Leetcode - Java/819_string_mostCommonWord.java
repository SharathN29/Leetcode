// https://leetcode.com/problems/most-common-word/

class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        Set<String> bannedWords = new HashSet(Arrays.asList(banned));
        Map<String, Integer> wordCount = new HashMap(); 
        String[] words = paragraph.replaceAll("\\W+", " ").toLowerCase().split("\\s+");
        
        for (String w : words) {
            if (!bannedWords.contains(w)) {
                wordCount.put(w, wordCount.getOrDefault(w, 0) + 1);
            }
        }
        
        return Collections.max(wordCount.entrySet(), Map.Entry.comparingByValue()).getKey();
    }
}