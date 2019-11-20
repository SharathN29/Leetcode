package com.sharath;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
	    Solution solution = new Solution();
	    int[] king = {0,0};
	    int[][] queens = {{0,1},{1,0},{0,4},{4,0},{3,3},{2,4}};
        System.out.println(Arrays.deepToString(solution.queensAttacktheKing(queens,king).toArray()));
    }
}
