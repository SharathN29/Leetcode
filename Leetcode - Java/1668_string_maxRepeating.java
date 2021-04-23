// https://leetcode.com/problems/maximum-repeating-substring/

class Solution {
    public int maxRepeating(String sequence, String word) {
        int ans = 1; 
        while (sequence.indexOf(word.repeat(ans)) >= 0) {
            ans++;
        }
        return ans - 1;
    }
}