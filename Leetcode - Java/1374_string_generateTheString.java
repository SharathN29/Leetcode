// https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/

class Solution {
    public String generateTheString(int n) {
        return "a".repeat(n - (n + 1) % 2) + "b".repeat((n + 1) % 2);
    }
}