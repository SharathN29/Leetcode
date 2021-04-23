// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/

class Solution {
    public boolean canThreePartsEqualSum(int[] arr) {
        int sum = Arrays.stream(arr).sum(), average = sum / 3;
        int l = 0, r = arr.length - 1;
        int leftsum = arr[l++], rightsum = arr[r--];
        
        do {
            if (leftsum != average) {
                leftsum += arr[l++];
            }
            if (l < r && rightsum != average) {
                rightsum += arr[r--];
            }
            if (l <= r && sum % 3 == 0 && leftsum == average && rightsum == average) {
                return true;
            } 
        } while (l < r);
        return false;
    }
}