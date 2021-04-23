// https://leetcode.com/problems/most-visited-sector-in-a-circular-track/

class Solution {
    public List<Integer> mostVisited(int n, int[] rounds) {
        int start = rounds[0], end = rounds[rounds.length - 1];
        List<Integer> res = new ArrayList();

        if (start <= end) {
            while (start <= end) {
                res.add(start++);
            }
        } else {
            int i = 1;
            while (i <= end) {
                res.add(i++);
            }
            while (start <= n) {
                res.add(start++);
            }
        }
        return res;
    }
}
