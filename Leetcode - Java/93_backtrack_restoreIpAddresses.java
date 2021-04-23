// https://leetcode.com/problems/restore-ip-addresses/

class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> allIp = new ArrayList();
        int[] path = new int[4];
        backtrack(allIp, s, 0, path, 0);
        return allIp;
    }
    
    public void backtrack(List<String> allIp, String s, int builderIdx, int[] path, int segment) {
        if (segment == 4 && builderIdx == s.length()) {
            allIp.add(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            return;
        } else if (segment == 4 || builderIdx == s.length()) {
            return;
        }
        
        for (int len = 1; len <= 3 && builderIdx + len <= s.length(); len++) {
            String snap = s.substring(builderIdx, builderIdx + len);
            int val = Integer.parseInt(snap);
            if (val > 255 || len >= 2 && s.charAt(builderIdx) == '0') {
                break;
            }
            path[segment] = val;
            backtrack(allIp, s, builderIdx + len, path, segment + 1);
            path[segment] = 0;
        }
    }
}