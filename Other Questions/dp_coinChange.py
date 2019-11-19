"""
Coin Change : https://leetcode.com/problems/coin-change/
Author : Sharath Nagendra

Passes all leetcode test cases as on Oct 3, 2019
Runtime: 1020 ms, faster than 80.57% of Python online submissions for Coin Change.
Memory Usage: 11.9 MB, less than 62.50% of Python online submissions for Coin Change.
"""
def coinChange(coins, amount):
    dp = [0] + [float('inf')] * amount 
    for coin in coins:
        for i in range(coin, amount+1):
            dp[i] = min(dp[i], dp[i-coin]+1)
    return dp[-1] if dp[-1] != float('inf') else -1

coins, amount = [1,2,5], 11
print(coinChange(coins, amount))