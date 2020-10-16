// https://leetcode.com/problems/permutation-sequence/

class Solution {
    public String getPermutation(int n, int k) {
        int[] factorial = new int[n];
        List<Integer> nums = new ArrayList() {{add(1);}};
        
        factorial[0] = 1;
        for (int i = 1; i < n; i++) {
            factorial[i] = factorial[i-1] * i;
            nums.add(i + 1);
        }
        k--;
        
        StringBuilder sb = new StringBuilder(); 
        for (int i = n - 1; i > -1; i--) {
            int idx = k / factorial[i];
            k -= idx * factorial[i];
            
            sb.append(nums.get(idx));
            nums.remove(idx);
        }
        return sb.toString();
    }
}