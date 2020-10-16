// https://leetcode.com/problems/find-common-characters/

class Solution {
    public List<String> commonChars(String[] A) {
        List<String> res = new ArrayList();
        int[] count = new int[26];
        Arrays.fill(count, Integer.MAX_VALUE);
        
        for (String str : A) {
            int[] cnt = new int[26];
            str.chars().forEach(c -> ++cnt[c - 'a']);
            for (int i = 0; i < 26; i++) {
                count[i] = Math.min(count[i], cnt[i]);
            }
        }
        
        for (char c = 'a'; c <= 'z'; c++) {
            while (count[c - 'a']-- > 0) {
                res.add("" + c);
            }
        }
        
        return res;
    }
}