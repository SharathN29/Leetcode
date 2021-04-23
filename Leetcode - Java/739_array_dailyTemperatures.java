// https://leetcode.com/problems/daily-temperatures/

class Solution {
    public int[] dailyTemperatures(int[] T) {
        int len = T.length;
        int[] res = new int[len];
        Stack<Integer> s = new Stack();
        
        for (int i = 0; i < len; i++) {
            while (!s.isEmpty() && T[i] > T[s.peek()]) {
                int idx = s.pop();
                res[idx] = i - idx;
            }
            s.push(i);
        }
        return res;
    }
}