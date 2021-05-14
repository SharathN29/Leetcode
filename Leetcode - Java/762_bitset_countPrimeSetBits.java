// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

class Solution {
    public int countPrimeSetBits(int L, int R) {
        int count = 0;
        for (int i = L; i <= R; i++) {
            String binary = Integer.toBinaryString(i);
            if (hasPrimeBits(binary)) count++;
        }
        return count; 
    }
    
    private boolean hasPrimeBits(String binary) {
        int setBits = 0;
        for (char c : binary.toCharArray()) {
            if (c == '1') setBits++;
        }
        return isPrime(setBits);
    }
    
    private boolean isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
  
        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
  
        return true;
    }
}