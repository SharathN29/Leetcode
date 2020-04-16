// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

class Solution {
    public int subtractProductAndSum(int n) {
        int prod = productDigits(n);
        int sum = sumDigits(n);
        return prod-sum;
    }
    
    private int productDigits(int n) {
        int product = 1; 
        while(n > 0) {
            int digit = n % 10;
            product *= digit; 
            n /= 10;
        }
        return product; 
    }
    
    private int sumDigits(int n) {
        int sum = 0; 
        while(n > 0) {
            int digit = n % 10;
            sum += digit; 
            n /= 10;
        }
        return sum; 
    }
}