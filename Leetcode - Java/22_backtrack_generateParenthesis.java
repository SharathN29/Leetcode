// https://leetcode.com/problems/generate-parentheses/

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList();
        backtrack(res, "", 0, 0, n);
        return res;
    }
    
    private void backtrack(List<String> res, String s, int open, int close, int maxLen) {
        if (s.length() == 2 * maxLen) {
            res.add(s);
            return;
        }
        if (open < maxLen) {
            backtrack(res, s + "(", open + 1, close, maxLen);
        }
        if (close < open) {
            backtrack(res, s + ")", open, close + 1, maxLen);
        }
    }
}