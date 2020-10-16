// https://leetcode.com/problems/longest-repeating-substring/

class Solution {
    public int longestRepeatingSubstring(String S) {
        int n = S.length();
        int[] nums = new int[n];
        
        for (int i = 0; i < n; i++) {
            nums[i] = (int)S.charAt(i) - (int)'a';
        }
        
        int a = 26; 
        long modulus = (long) Math.pow(2, 24);
        
        int left = 1, right = n; 
        int l;
        
        while (left <= right) {
            l = (left + right) / 2; 
            if (search(l, a, modulus, n, nums) != -1) left = l + 1;
            else right = l - 1; 
        }
        return left - 1; 
    }
    
    public int search (int l, int a, long modulus, int n, int[] nums) {
        long h = 0; 
        for (int i = 0; i < l; i++) {
            h = (h * a + nums[i]) % modulus; 
        }
            
        HashSet<Long> seen = new HashSet();
        seen.add(h);

        long al = 1; 
        for (int i = 1; i <= l; ++i) {
            al = (al * a) % modulus; 
        }

        for (int start = 1; start < n - l + 1; start++) {
            h = (h * a - nums[start - 1] * al % modulus + modulus) % modulus; 
            h = (h + nums[start + l -1]) % modulus; 

            if (seen.contains(h))
                return start;

            seen.add(h);
        }
        return -1; 
    }
}