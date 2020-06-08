// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3289/

class Solution {
    public int countElements(int[] arr) {
        Set<Integer> s = new HashSet<Integer>();
        for(int n : arr) {
            s.add(n);
        }
        int count = 0;
        for(int n : arr) {
            if(s.contains(n+1)) {
                count++;
            }
        }
        return count; 
    }
}