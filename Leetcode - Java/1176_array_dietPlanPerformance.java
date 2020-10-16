// https://leetcode.com/problems/diet-plan-performance/

class Solution {
    public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
        int points = 0;
        for (int i = 0, win = 0; i < calories.length; i++) {
            win += calories[i];
            if (i >= k - 1) {
                if (i > k - 1) win -= calories[i - k];
                if (win < lower) points--;
                else if (win > upper) points++;
            }
        }
        return points;
    }
}