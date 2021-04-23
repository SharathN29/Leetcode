// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

class Solution {
    public int longestSubstring(String s, int k) {
        return longestSubstring(s, 0, s.length(), k);
    }
    
    public int longestSubstring(String s, int start, int end, int k) {
        if (end < k) return 0;
        int[] count = new int[26];
        
        for (int i = start; i < end; i++) {
            count[s.charAt(i) - 'a']++;
        }
        
        for (int mid = start; mid < end; mid++) {
            if (count[s.charAt(mid) - 'a'] >= k) continue;
            int midnext = mid + 1;
            while (midnext < end && count[s.charAt(midnext) - 'a'] < k) midnext++;
            return Math.max(longestSubstring(s, start, mid, k), longestSubstring(s, midnext, end, k));
        }
        
        return (end - start);
    }
}