// https://leetcode.com/problems/find-lucky-integer-in-an-array/

class Solution {
    public int findLucky(int[] arr) {
        Map<Integer, Integer> counts = new HashMap();
        for(Integer n : arr) {
            counts.put(n, counts.getOrDefault(n, 0) + 1);
        }
        
        int luckyNumber = -1; 
        
        for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
            if (entry.getKey().equals(entry.getValue())) {
                luckyNumber = Math.max(luckyNumber, entry.getKey());
            }
        }
        
        return luckyNumber;
    }
}