// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3287/

class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        for(int i = 1; i < prices.length; i++) {
            if(prices[i] > prices[i-1]) 
                maxProfit += prices[i] - prices[i-1];
        }
        return maxProfit; 
    }
}