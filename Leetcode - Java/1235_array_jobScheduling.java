// https://leetcode.com/problems/maximum-profit-in-job-scheduling/

class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        List<int[]> list = new ArrayList<>();
        for(int i = 0; i < n; i++){
            list.add(new int[]{startTime[i], endTime[i], profit[i]});
        }
        Collections.sort(list, (a, b) -> a[1] - b[1]);
        TreeMap<Integer, Integer> ans = new TreeMap<>();
        ans.put(0, 0);
        for(int[] time : list){
            int previous_ans = 0;
            if(!ans.isEmpty()) previous_ans = ans.get(ans.lastKey());
            int start = time[0], end = time[1], p = time[2];
            int time_before_start = ans.floorKey(start);
            int cur_ans = ans.get(time_before_start) + p;
            ans.put(end, Math.max(previous_ans, cur_ans));
        }
        return ans.get(ans.lastKey());
    }
}