package com.sharath;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
	    Solution solution = new Solution();
	    int[][] items = {{1,91}, {1,90}, {2,99}, {2,89}, {1,94},{1,33},{1,88}, {2,45}, {2,88}, {2,85}, {2,31}};
        System.out.println(Arrays.deepToString(solution.highFive(items)));
    }
}
