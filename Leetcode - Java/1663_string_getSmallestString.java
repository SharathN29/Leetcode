// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

class Solution {
    public String getSmallestString(int n, int k) {
        char[] res = new char[n];
        Arrays.fill(res, 'a');
        k -= n;
        
        for (int i = n - 1; i >= 0 && k > 0; i--) {
            int add = Math.min(k, 25);
            res[i] = (char) (res[i] + add);
            k -= add;
        }
        return new String(res);
    }
}