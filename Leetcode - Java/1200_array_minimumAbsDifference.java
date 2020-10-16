// https://leetcode.com/problems/minimum-absolute-difference/

class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        List<List<Integer>> res = new ArrayList();
        int diff = Integer.MAX_VALUE;
        
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] - arr[i - 1] <= diff) {
                if (arr[i] - arr[i - 1] < diff) {
                    diff = arr[i] - arr[i - 1];
                    res = new ArrayList();
                }
                res.add(Arrays.asList(arr[i - 1], arr[i]));
            }
        }
        return res;
    }
}