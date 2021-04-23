// https://leetcode.com/problems/minimum-window-substring/

class Solution {
    public String minWindow(String s, String t) {
        if (s.length() == 0 || t.length() == 0) return "";
        
        Map<Character, Integer> dictT = new HashMap();
        for (char c : t.toCharArray()) {
            dictT.put(c, dictT.getOrDefault(c,0)+1);
        }
        
        int required = dictT.size();
        int l = 0, r = 0;
        int formed = 0;
        
        Map<Character, Integer> window = new HashMap();
        int[] res = {-1, 0, 0};
        
        while (r < s.length()) {
            char c = s.charAt(r);
            window.put(c, window.getOrDefault(c, 0)+1);
            
            if (dictT.containsKey(c) && window.get(c).intValue() == dictT.get(c).intValue()) {
                formed++;
            }
            
            while (l <= r && formed == required) {
                c = s.charAt(l);
                if (res[0] == -1 || r - l + 1 < res[0]) {
                    res[0] = r - l + 1;
                    res[1] = l; 
                    res[2] = r;
                }
                window.put(c, window.get(c) - 1);
                if (dictT.containsKey(c) && window.get(c).intValue() < dictT.get(c).intValue()) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return res[0] == -1 ? "" : s.substring(res[1], res[2]+1);
    }
}