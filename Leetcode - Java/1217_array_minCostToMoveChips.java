// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/

class Solution {
    public int minCostToMoveChips(int[] position) {
        int evenCount = 0, oddCount = 0;
        for (int p : position) {
            if (p % 2 == 0) evenCount++;
            else oddCount++;
        }
        return Math.min(evenCount, oddCount);
    }
}