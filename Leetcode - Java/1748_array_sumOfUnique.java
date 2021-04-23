// https://leetcode.com/problems/sum-of-unique-elements/

class Solution {
    public int sumOfUnique(int[] nums) {
        Map<Integer, Integer> countElem = new HashMap();
        for (int n : nums) {
            countElem.put(n, countElem.getOrDefault(n, 0) + 1);
        }
        
        int sum = 0;
        for (int n : countElem.keySet()) {
            if (countElem.get(n) == 1) sum += n;
        }
        
        return sum;
    }
}