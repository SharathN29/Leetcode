// https://leetcode.com/problems/remove-interval/

class Solution {
    public List<List<Integer>> removeInterval(int[][] intervals, int[] toBeRemoved) {
        int removeStart = toBeRemoved[0], removeEnd = toBeRemoved[1];
        List<List<Integer>> res = new ArrayList();

        for (int[] interval : intervals) {
            int start = interval[0], end = interval[1];

            if (start >= removeEnd || end <= removeStart) {
                res.add(new ArrayList() {{add(start); add(end);}});
            } else if (start < removeStart && end > removeEnd) {
                res.add(new ArrayList() {{add(start); add(removeStart);}});
                res.add(new ArrayList() {{add(removeEnd); add(end);}});
            } else if (start < removeStart && end <= removeEnd) {
                res.add(new ArrayList() {{add(start); add(removeStart);}});
            } else if (start >= removeStart && end > removeEnd) {
                res.add(new ArrayList() {{add(removeEnd); add(end);}});
            }
        }

        return res;
    }
}
