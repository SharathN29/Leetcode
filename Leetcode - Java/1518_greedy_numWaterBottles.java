// https://leetcode.com/problems/water-bottles/

class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        while (numBottles >= numExchange) {
            int newBottles = numBottles % numExchange; 
            numBottles /= numExchange;
            res += numBottles;
            numBottles += newBottles;
        }
        return res;
    }
}