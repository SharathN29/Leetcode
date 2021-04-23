// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3353/

class Solution {
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount+1];
        dp[0] = 1;
        
        for(int coin : coins) {
            for(int x = coin; x < amount+1; x++) {
                dp[x] += dp[x-coin];
            }
        }
        
        return dp[amount];
    }
}