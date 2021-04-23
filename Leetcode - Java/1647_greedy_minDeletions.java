// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class Solution {
    public int minDeletions(String s) {
        int cnt[] = new int[26], res = 0;
        Set<Integer> used = new HashSet<>();
        for (int i = 0; i < s.length(); ++i)
            ++cnt[s.charAt(i) - 'a'];
        for (int i = 0; i < 26; ++i) {
            int freq = cnt[i];
            while (freq > 0 && !used.add(freq)) {
                --freq;
                ++res;
            }
        }        
        return res;
    }
}