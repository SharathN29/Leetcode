// https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/

class Solution {
    public boolean isCovered(int[][] ranges, int left, int right) {
        Set<Integer> integersIncluded = new HashSet();
        
        for (int[] range : ranges) {
            for (int i = range[0]; i <= range[1]; i++) {
                integersIncluded.add(i);
            }
        }
        
        for (int i = left; i <= right; i++) {
            if (!integersIncluded.contains(i)) return false;
        }
        return true;
    }
}