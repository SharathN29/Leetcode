"""
Best Time to Buy And Sell Stocks : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Author : Sharath Nagendra 

Passes all leetcode test cases as of Oct 16 2019
Runtime: 48 ms, faster than 66.59% of Python online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 12.7 MB, less than 21.10% of Python online submissions for Best Time to Buy and Sell Stock.
"""
class Solution(object):
    def maxProfitStocks(self, prices): 
        if not prices:
            return 0
        minPrice, maxProfit = prices[0], 0
        for i in range(1, len(prices)):
            minPrice = min(minPrice, prices[i])
            maxProfit = max(maxProfit, prices[i] - minPrice)
        return maxProfit

mp = Solution()
prices = [7,1,5,3,6,4]
print(mp.maxProfitStocks(prices))