// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/

class Solution {
    public int minSwaps(int[][] grid) {
        int[] arr = gridToArray(grid);
        return minSwaps(arr);
    }
    
    private int[] gridToArray(int[][] grid) {
        int[] arr = new int[grid.length];
        int i = 0;
        for (int[] g : grid) {
            arr[i++] = zerosInTheEnd(g);
        }
        return arr;
    }
    
    private int zerosInTheEnd(int[] g) {
        int ans = 0;
        int n = g.length;
        int i = n - 1;
        while (i >= 0 && g[i] == 0) {
            ans++;
            i--;
        }
        return ans; 
    }
    
    private int minSwaps(int[] a) {
        int n = a.length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < n - i - 1) {
                int j = i;
                while (j < n && a[j] < n - i - 1) {
                    j++;
                }
                
                if (j == n) {
                    return -1;
                }
                
                while (j > i) {
                    int temp = a[j];
                    a[j] = a[j-1];
                    a[j-1] = temp;
                    ans++;
                    j--;
                }
            }
        }
        return ans;
    }
}