// https://leetcode.com/problems/crawler-log-folder/

class Solution {
    public int minOperations(String[] logs) {
        int steps = 0;
        for (String s : logs) {
            if (s.equals("../")) steps = Math.max(0, --steps);
            else if (s.equals("./")) continue; 
            else steps++;
        }
        return steps;
    }
}