"""
Best Time to Buy and Sell Stock II : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
Author : Sharath Nagendra 

Passes all leetcode test cases as of Oct 16 2019

"""
class Solution(object):
    def maxProfit(self, prices):
        res = []
        for i in range(len(prices)-1):
            if prices[i+1] > prices[i]:
                res.append(prices[i+1]-prices[i])
        return sum(res)

mp = Solution()
prices = [7,1,5,3,6,4]
print(mp.maxProfit(prices))