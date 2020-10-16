// https://leetcode.com/problems/confusing-number/

class Solution {
    public boolean confusingNumber(int N) {
        Map<Integer, Integer> map = new HashMap();
        map.put(6, 9);
        map.put(9, 6);
        map.put(0, 0);
        map.put(1, 1);
        map.put(8, 8);
        int newNum = 0, n = N;
        
        while (n != 0) {
            int rem = n % 10;
            if (!map.containsKey(rem)) return false; 
            if (newNum > Integer.MAX_VALUE / 10) return false; 
            newNum = newNum * 10 + map.get(rem);
            n = n / 10;
        }
        return N == newNum ? false : true; 
    }
}