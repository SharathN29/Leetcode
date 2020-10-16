// https://leetcode.com/problems/maximum-profit-of-operating-a-centennial-wheel/

class Solution {
    public int minOperationsMaxProfit(int[] customers, int boardingCost, int runningCost) {
        int waitingCustomers = customers[0], totalOnBoard = 0;
        int res = -1, maxProfit = 0;
        
        for (int i = 1; i < customers.length || waitingCustomers > 0; i++) {
            int newOnBoard = Math.min(4, waitingCustomers);
            waitingCustomers -= newOnBoard;
            totalOnBoard += newOnBoard;
            
            int profit = totalOnBoard * boardingCost - i * runningCost;
            if (profit > maxProfit) {
                maxProfit = profit;
                res = i;
            }
            
            if (i < customers.length) waitingCustomers += customers[i];
        }
        return res;
    }
}