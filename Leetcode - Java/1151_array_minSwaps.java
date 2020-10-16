// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/

class Solution {
    public int minSwaps(int[] data) {
        if (data.length < 3) return 0;
        int n = 0;
        for (int d : data) 
            if (d == 1)
                n++;
        
        int i = 0, j = 0, c = 0, max = 0;
        while (j < data.length) {
            while (j < data.length && j - i < n) {
                if (data[j++] == 1) c++;
            }
            max = Math.max(max, c);
            if (j == data.length) break;
            
            if (data[i++] == 1) c--;
        }
        return n - max;
    }
}