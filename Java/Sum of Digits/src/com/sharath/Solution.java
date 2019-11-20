package com.sharath;

import java.util.Arrays;

public class Solution {
    public int sumOfDigits(int[] A) {
        int min = Arrays.stream(A).min().getAsInt();
        int sum = 0;
        while(min/10>=1){
            sum += min%10;
            min = min/10;
        }
        sum += min;
        if(sum%2 == 0)
            return 1;
        else return 0;
    }
}
