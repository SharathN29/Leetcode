// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

class Solution {
    public int getLucky(String s, int k) {
        int sum = 0, temp = 0;
        for (int i = 0; i < s.length(); i++) {
            int digit = (int)s.charAt(i) - 96;
            sum += digit % 10 + digit / 10;
        }
        
        while (--k > 0 && sum > 9) {
            temp = 0;
            while (sum > 0) {
                temp += sum % 10;
                sum /= 10;
            }
            sum = temp;
        }
        return sum;
    }
}