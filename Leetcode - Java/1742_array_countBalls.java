// https://leetcode.com/problems/maximum-number-of-balls-in-a-box/

class Solution {
    public int countBalls(int lowLimit, int highLimit) {
        Map<Integer, Integer> ballCount = new HashMap();
        int maxBalls = 0;
        int boxNum = 0;
        
        for (int i = lowLimit; i <= highLimit; i++) {
            boxNum = getSumOfDigits(i);
            ballCount.put(boxNum, ballCount.getOrDefault(boxNum, 0) + 1);
            maxBalls = Math.max(maxBalls, ballCount.get(boxNum));
        }
        
        return maxBalls;
    }
    
    public int getSumOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
}