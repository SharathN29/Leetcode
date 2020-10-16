// https://leetcode.com/problems/consecutive-characters/

class Solution {
    public int maxPower(String s) {
        int max = -1;
        int currCount = 1;
        char[] sChar = s.toCharArray();
        
        for(int i = 1; i < sChar.length; i++) {
            if(sChar[i] == sChar[i-1]) {
                currCount++;
            } else {
                if(currCount > max) {
                    max = currCount;
                }
                currCount = 1;
            }
        }
        return Math.max(max, currCount);
    }
}