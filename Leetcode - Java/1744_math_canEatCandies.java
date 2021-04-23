// https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/

class Solution {
    public boolean[] canEat(int[] candiesCount, int[][] queries) {
        boolean[] res = new boolean[queries.length];
        long[] count = new long[candiesCount.length];
        count[0] = candiesCount[0];
        
        for (int i = 1; i < candiesCount.length; i++) {
            count[i] += (candiesCount[i] + count[i - 1]);
        }
        
        for (int i = 0; i < queries.length; i++) {
            int type = queries[i][0], day = queries[i][1];
            long cap = queries[i][2];
            long max = (day + 1) * cap;
            
            res[i] = (max > ((type == 0) ? 0 : count[type - 1]) && day + 1 <= count[type]);
        }
        
        return res;
    }
}