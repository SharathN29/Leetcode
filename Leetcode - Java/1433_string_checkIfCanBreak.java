// https://leetcode.com/problems/check-if-a-string-can-break-another-string/

class Solution {
    public boolean checkIfCanBreak(String s1, String s2) {
        int n = s1.length();
        int[] s1arr = new int[26], s2arr = new int[26];
        for (int i = 0; i < n; i++) {
            s1arr[s1.charAt(i) - 'a']++;
            s2arr[s2.charAt(i) - 'a']++;
        }
        
        int count1 = 0, count2 = 0;
        boolean f1 = false, f2 = false; 
        
        for (int i = 0; i < 26; i++) {
            count1 += s1arr[i];
            count2 += s2arr[i];
            
            if (count1 > count2) {
                if (f2) return false;
                f1 = true;
            } else if (count2 > count1) {
                if (f1) return false;
                f2 = true;
            }
        }
        return true;
    }
}