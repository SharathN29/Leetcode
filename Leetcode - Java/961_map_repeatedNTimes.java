// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

class Solution {
    public int repeatedNTimes(int[] A) {
        int len = A.length / 2; 
        Map<Integer, Integer> count = new HashMap();
        
        for (int a : A) {
            int c = count.getOrDefault(a, 0);
            if (c == len - 1) return a; 
            count.put(a, c + 1);
        }
        
        return -1;
    }
}