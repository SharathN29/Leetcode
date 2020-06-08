// https://leetcode.com/problems/height-checker/

class Solution {
    public int heightChecker(int[] heights) {
        int[] sortedHeights = new int[heights.length];
        sortedHeights = heights.clone(); 
        Arrays.sort(sortedHeights);
        
        int res = 0;
        for(int i = 0; i < heights.length; i++) {
            if(heights[i] != sortedHeights[i])
                res++;
        }
        return res; 
    }
}