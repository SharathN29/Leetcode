// https://leetcode.com/problems/reverse-words-in-a-string-ii/

class Solution {
    public void reverseWords(char[] s) {
        reverse(s, 0, s.length-1);
        reverseEachWords(s);
    }
    
    public void reverse(char[] s, int left, int right) {
        while(left < right) {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }
    
    public void reverseEachWords(char[] s) {
        int n = s.length;
        int start = 0, end = 0;
        
        while(start < n) {
            while(end < n && s[end] != ' ') ++end;
            reverse(s, start, end-1);
            start = end+1;
            ++end;
        }
    }
}