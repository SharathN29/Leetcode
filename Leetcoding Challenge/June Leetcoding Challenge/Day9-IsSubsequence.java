// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3355/

class Solution {

    public boolean isSubsequence(String s, String t) {
        Integer leftBound = s.length(), rightBound = t.length();
        Integer pLeft = 0, pRight = 0;

        while (pLeft < leftBound && pRight < rightBound) {
            if (s.charAt(pLeft) == t.charAt(pRight)) {
                pLeft += 1;
            }
            pRight += 1;
        }
        return pLeft == leftBound;
    }
}