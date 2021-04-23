// https://leetcode.com/problems/brick-wall/

class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        int res = Integer.MIN_VALUE;
        Map<Integer, Integer> map = new HashMap();
        
        for (List<Integer> w : wall) {
            int width = 0;
            for (int i = 0; i < w.size() - 1; i++) {
                width += w.get(i);
                map.put(width, map.getOrDefault(width, 0) + 1);
            }
        }
        
        for (Map.Entry<Integer, Integer> m : map.entrySet()) {
            res = Math.max(res, m.getValue());
        }
        
        if (res == Integer.MIN_VALUE) res = 0;
        return wall.size() - res;
    }
}