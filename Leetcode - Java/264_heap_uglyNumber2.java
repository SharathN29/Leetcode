// https://leetcode.com/problems/ugly-number-ii/

class Ugly {
    public int[] nums = new int[1690];
    
    Ugly() {
        Set<Long> seen = new HashSet();
        PriorityQueue<Long> heap = new PriorityQueue<Long>();
        seen.add(1L);
        heap.add(1L);
        
        long currentUgly, newUgly; 
        int[] primes = new int[]{2, 3, 5};
        
        for (int i = 0; i < 1690; i++) {
            currentUgly = heap.poll();
            nums[i] = (int)currentUgly; 
            for (int j : primes) {
                newUgly = currentUgly * j; 
                if (!seen.contains(newUgly)) {
                    seen.add(newUgly);
                    heap.add(newUgly);
                }
            }
        }
    }
}

class Solution {
    public static Ugly u = new Ugly();
    
    public int nthUglyNumber(int n) {
        return u.nums[n-1];
    }
}