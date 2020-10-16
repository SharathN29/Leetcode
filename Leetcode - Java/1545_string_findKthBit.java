// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

class Solution {
    public char findKthBit(int n, int k) {
        String[] s = new String[n];
        s[0] = "0";
        
        for (int i = 1; i < n; i++) {
            s[i] = s[i-1] + "1" + reverse(inverse(s[i-1]));
        }
        return s[n-1].charAt(k-1);
    }
    
    public String inverse(String s) {
        char[] str = s.toCharArray();
        for (int i = 0; i < str.length; i++) {
            if (str[i] == '0') str[i] = '1';
            else str[i] = '0';
        }
        return new String(str);
    }
    
    public String reverse(String s) {
        int i = 0, j = s.length() - 1;
        char[] str = s.toCharArray();
        while (i < j) {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++; j--;
        }
        return new String(str);
    }
}