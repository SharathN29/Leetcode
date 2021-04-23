// https://leetcode.com/problems/mean-of-array-after-removing-some-elements/

class Solution {
    public double trimMean(int[] arr) {
        int len = arr.length;
        int trimLen = (5 * len) / 100;
        Arrays.sort(arr);
        int[] newArr = Arrays.copyOfRange(arr, trimLen, len - trimLen);
        double mean = 0;
        for (int a : newArr) {
            mean += a;
        }
        return mean / newArr.length;
    }
}