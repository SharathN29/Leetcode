// https://leetcode.com/problems/slowest-key/

class Solution {
    public char slowestKey(int[] releaseTimes, String keysPressed) {
        int maxDuration = releaseTimes[0];
        char res = keysPressed.charAt(0);
        
        for (int i = 1; i < keysPressed.length(); i++) {
            int currDuration = releaseTimes[i] - releaseTimes[i - 1];
            char currChar = keysPressed.charAt(i);
            if (currDuration >= maxDuration) {
                res = currDuration == maxDuration ? res > currChar ? res : currChar : currChar;
                maxDuration = currDuration;
            } 
        }
        return res;
    }
}