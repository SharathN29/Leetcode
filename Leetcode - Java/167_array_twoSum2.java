// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] res = {-1,-1};
        int low = 0, high = numbers.length-1;
        
        while(low < high) {
            int sum = numbers[low] + numbers[high];
            if(sum == target) {
                res[0] = low+1;
                res[1] = high+1;
                return res;
            }
            else if(sum < target) ++low;
            else --high;
        }
        return res; 
    }
}