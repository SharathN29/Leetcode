// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        int i = 0, len = 0;
        Map<Character, Integer> freqMap = new HashMap();
        
        for (int j = 0; j < s.length(); j++) {
            freqMap.put(s.charAt(j), freqMap.getOrDefault(s.charAt(j), 0) + 1);
            while (freqMap.size() > 2) {
                char left = s.charAt(i++);
                freqMap.put(left, freqMap.get(left) - 1);
                if (freqMap.get(left) == 0) {
                    freqMap.remove(left);
                }
            }
            len = Math.max(len, j - i + 1);
        }
        return len;
    }
}