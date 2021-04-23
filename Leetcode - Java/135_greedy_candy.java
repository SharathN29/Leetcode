// https://leetcode.com/problems/candy/

class Solution {
    public int candy(int[] ratings) {
        int size = ratings.length;
        if (size <= 1) {
            return size; 
        }
        
        int[] num = new int[size];
        Arrays.fill(num, 1);
        
        for (int i = 1; i < size; i++) {
            if (ratings[i] > ratings[i - 1]) {
                num[i] = num[i - 1] + 1;
            }
        }
        
        for (int i = size - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i]) {
                num[i - 1] = Math.max(num[i] + 1, num[i - 1]);
            }
        }
        
        int candies = 0;
        for (int n : num) {
            candies += n;
        }
        
        return candies;
    }
}