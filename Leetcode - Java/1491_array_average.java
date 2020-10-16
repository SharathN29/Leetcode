// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

class Solution {
    public double average(int[] salary) {
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        double sum = 0d; 
        
        for (int s : salary) {
            min = Math.min(s, min);
            max = Math.max(s, max);
            sum += s;
        }
        
        return (sum - min - max) / (salary.length - 2);
    }
}