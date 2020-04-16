// https://leetcode.com/problems/happy-number/

class Solution {
    public boolean isHappy(int n) {
        int slow, fast; 
        slow = fast = n;
        do {
            slow = sumOfNums(slow);
            fast = sumOfNums(fast);
            fast = sumOfNums(fast);
            if(fast == 1) return true; 
        } while(slow != fast);
        return false; 
    }
    
    private int sumOfNums(int num) {
        int sum = 0, temp;
        while(num > 0) {
            temp = num % 10;
            sum += temp * temp;
            num /= 10;
        }
        return sum;
    }
}