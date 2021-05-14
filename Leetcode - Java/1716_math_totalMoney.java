// https://leetcode.com/problems/calculate-money-in-leetcode-bank/

class Solution {
    public int totalMoney(int n) {
        int currMoney = 1; 
        int totalMoney = 1;
        
        for (int i = 1; i < n; i++) {
            if (i % 7 == 0) {
                currMoney = (i / 7);
            } 
            currMoney++;
            totalMoney += currMoney;
        }
        return totalMoney;
    }
}