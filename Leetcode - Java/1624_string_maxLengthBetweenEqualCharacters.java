// https://leetcode.com/problems/largest-substring-between-two-equal-characters/

class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        Map<Character, Integer> charIndex = new HashMap();
        int res = Integer.MIN_VALUE;
        for (int i = 0; i < s.length(); i++) {
            if (charIndex.containsKey(s.charAt(i))) {
                res = Math.max(res, i - charIndex.get(s.charAt(i)) - 1);
            } else {
                charIndex.put(s.charAt(i), i);
            }
        }
        return res <= Integer.MIN_VALUE ? -1 : res;
    }
}