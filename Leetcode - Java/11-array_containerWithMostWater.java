// https://leetcode.com/problems/container-with-most-water/

class Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length-1, max_area = 0;
        
        while(left < right) {
            max_area = Math.max(max_area, Math.min(height[left], height[right])*(right-left));
            if(height[left] < height[right]) left++;
            else right--;
        }
        return max_area;
    }
}