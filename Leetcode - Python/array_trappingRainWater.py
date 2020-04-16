"""
Trapping Rain Water : https://leetcode.com/problems/trapping-rain-water/
Author : Sharath Nagendra

Passes all leetcode test cases as on Oct 5 2019
Runtime: 32 ms, faster than 90.53% of Python online submissions for Trapping Rain Water.
Memory Usage: 12.4 MB, less than 28.77% of Python online submissions for Trapping Rain Water.
"""
def trap(height):
    if not height or len(height) < 3:
        return 0
    volume = 0
    left, right = 0, len(height)-1
    lMax, rMax = height[0], height[right]
    while left < right:
        lMax, rMax = max(height[left], lMax), max(height[right], rMax)
        if lMax <= rMax:
            volume += lMax - height[left]
            left += 1
        else:
            volume += rMax - height[right]
            right -= 1
    return volume

print(trap([0,1,0,2,1,0,1,3,2,1,2,1]))