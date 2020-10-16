// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

class Solution {
    public int maxUniqueSplit(String s) {
        Set<String> set = new HashSet();
        return dfs(set, 0, s); 
    }
    
    public int dfs(Set<String> set, int idx, String s) {
        if (idx >= s.length()) return 0;
        int res = -1; 
        for (int i = idx + 1; i <= s.length(); i++) {
            String sub = s.substring(idx, i);
            if (set.contains(sub)) continue; 
            set.add(sub);
            int next = dfs(set, i, s);
            if (next >= 0) 
                res = Math.max(res, next + 1);
            set.remove(sub);
        }
        return res;
    }
}