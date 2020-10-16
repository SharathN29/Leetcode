// https://leetcode.com/problems/uncommon-words-from-two-sentences/

class Solution {
    public String[] uncommonFromSentences(String A, String B) {
        Map<String, Integer> wordCount = new HashMap();
        List<String> res = new ArrayList();
        
        for (String s : (A + " " + B).split(" ")) {
            wordCount.put(s, wordCount.getOrDefault(s, 0) + 1);
        }
        
        for (String word : wordCount.keySet()) {
            if (wordCount.get(word) == 1) {
                res.add(word);
            }
        }
        return res.toArray(new String[0]);
    }
}