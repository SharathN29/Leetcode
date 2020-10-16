// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        if (s == null || s.length() == 0 || s.length() < k) return s.length();
        
        int len = s.length();
        int i = 0, maxLen = 0; 
        Map<Character, Integer> freqMap = new HashMap();
        
        for (int j = 0; j < len; j++) {
            freqMap.put(s.charAt(j), freqMap.getOrDefault(s.charAt(j), 0) + 1);
            
            while (freqMap.size() > k) {
                char first = s.charAt(i++);
                freqMap.put(first, freqMap.get(first) - 1);
                
                if (freqMap.get(first) == 0) {
                    freqMap.remove(first);
                }
            }
            maxLen = Math.max(maxLen, j - i + 1);
        }
        
        return maxLen;
    }
}