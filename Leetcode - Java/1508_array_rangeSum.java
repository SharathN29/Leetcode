// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

class Solution {
    public int rangeSum(int[] nums, int n, int left, int right) {
        List<Integer> subarrays = new ArrayList();
        
        for (int i = 0; i < n; i++) {
            int sum = nums[i];
            subarrays.add(sum);
            
            for (int j = i + 1; j < n; j++) {
                sum += nums[j];
                subarrays.add(sum);
            }
        }
        
        Collections.sort(subarrays);
        int sum = 0;
        
        while (left <= right) {
            sum += subarrays.get (left++ - 1) % 1000000007;
        }
        
        return sum;
    }
}