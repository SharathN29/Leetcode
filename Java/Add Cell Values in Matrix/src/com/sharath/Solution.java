package com.sharath;

public class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        boolean[] row = new boolean[n], col = new boolean[m];
        for(int[] index : indices){
            row[index[0]] ^= true;
            col[index[1]] ^= true;
        }
        int count = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                count += row[i] ^ col[j] ? 1 : 0;
        return count;
    }
}
