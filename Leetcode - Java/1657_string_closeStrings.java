// https://leetcode.com/problems/determine-if-two-strings-are-close/

class Solution {
    public boolean closeStrings(String word1, String word2) {
        if (word1.length() != word2.length()) {
            return false;
        }
        Map<Character, Integer> word1Map = new HashMap();
        Map<Character, Integer> word2Map = new HashMap();

        for (char c : word1.toCharArray()) {
            word1Map.put(c, word1Map.getOrDefault(c, 0) + 1);
        }

        for (char c : word2.toCharArray()) {
            word2Map.put(c, word2Map.getOrDefault(c, 0) + 1);
        }

        if (!word1Map.keySet().equals(word2Map.keySet())) {
            return false;
        }
        List<Integer> word1FreqList = new ArrayList(word1Map.values());
        List<Integer> word2FreqList = new ArrayList(word2Map.values());

        Collections.sort(word1FreqList);
        Collections.sort(word2FreqList);

        return word1FreqList.equals(word2FreqList);
    }
}
