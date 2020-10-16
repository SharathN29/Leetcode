// https://leetcode.com/problems/put-boxes-into-the-warehouse-i/

class Solution {
    public int maxBoxesInWarehouse(int[] boxes, int[] warehouse) {
        Arrays.sort(boxes);
        int res = 0;
        int m = boxes.length, n = warehouse.length;
        for (int i = 0; i < m && res < n; i++) {
            if (boxes[m - i - 1] <= warehouse[res]) {
                res++;
            }
        }
        return res;
    }
}