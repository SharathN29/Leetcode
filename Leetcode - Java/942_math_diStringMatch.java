// https://leetcode.com/problems/di-string-match/

class Solution {
    public int[] diStringMatch(String S) {
        int N = S.length();
        int low = 0, high = N;
        int[] res = new int[N + 1];
        
        for (int i = 0; i < N; i++) {
            if (S.charAt(i) == 'I') res[i] = low++;
            else res[i] = high--;
        }
        res[N] = low;
        return res;
    }
}