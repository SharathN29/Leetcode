// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        Set<Integer> seen = new HashSet();
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE, n = arr.length; 
        
        for (int a : arr) {
            min = Math.min(min, a);
            max = Math.max(max, a);
            seen.add(a);
        }
        
        int diff = max - min; 
        if (diff % (n - 1) != 0) {
            return false;
        }
        
        diff /= n - 1;
        while (--n > 0) {
            if (!seen.contains(min)) {
                return false; 
            }
            min += diff;
        }
        return true;
    }
}