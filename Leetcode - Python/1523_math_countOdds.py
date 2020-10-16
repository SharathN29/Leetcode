# https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

class Solution(object):
    def countOdds(self, low, high):
        res = (high - low) / 2; 
        return res + 1 if (low % 2 != 0 or high % 2 != 0) else res; 
        
